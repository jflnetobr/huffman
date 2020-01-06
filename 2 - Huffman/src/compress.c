#include "../inc/compress.h"

huff_node *create_treefromfile(char filePath[], int frequency[])
{
    int i, caractere;

    priority_queue *queue = create_priority_queue();   
    huff_node *node_left, *node_right, *root;

    FILE *fileIn;
    fileIn = fopen(filePath, "r");

    while((caractere = getc(fileIn)) != EOF)
    {
        frequency[caractere]++;
    }

    for(i = 0; i < 256; i++)
    { 
        if(frequency[i] > 0) 
        {            
            unsigned char *item = (unsigned char*) malloc(sizeof(unsigned char));
            *item = i;
            enqueue_huffman_node(queue, create_huffman_node((void*) item, frequency[i]));
        }
    }   

    unsigned char *ast = (unsigned char*) malloc(sizeof(unsigned char));
    *ast = '*';

    while(has_next(queue))
    {
        node_left = dequeue_huffman_node(queue);
        node_right = dequeue_huffman_node(queue);

        root = create_huffman_node((void *) ast, node_left->freq + node_right->freq);
        
        root = place_tree_node(root, node_left, node_right);        

        enqueue_huffman_node(queue, root);
    }

    fclose(fileIn);

    return dequeue_huffman_node(queue);
}

unsigned char *create_header(int trashsize, int treesize)
{
  unsigned char *header = (unsigned char*) malloc(2 * sizeof(unsigned char));
  header[0] = (trashsize << 5) | (treesize >> 8);
  header[1] = treesize;

  return header;
}

void create_out_file(char fileInPath[], char fileOutPath[], unsigned char *header, code table[], huff_node *tree_root)
{
    FILE *fileIn, *fileOut;
    fileIn = fopen(fileInPath, "r");
    fileOut = fopen(fileOutPath, "w");

    fprintf(fileOut, "%c%c", header[0], header[1]);
    print_pre_order(tree_root, fileOut);

    fclose(fileIn);
    fclose(fileOut);
}

void compress(char fileInPath[], char fileOutPath[])
{
    int frequency[256], trashsize = 0, treesize = 0;
    memset(frequency, 0, 256 * sizeof(int));

    huff_node *root = create_treefromfile(fileInPath, frequency);

    code table[256], startcode;
    startcode.code = startcode.size = 0;
    memset(table, 0, 256 * sizeof(code));

    build_table(root, table, startcode);

    trashsize = get_trash_size(table, frequency);

    get_tree_size(root, &treesize);

    unsigned char *header = create_header(trashsize, treesize);

    create_out_file(fileInPath, fileOutPath, header, table, root);
}