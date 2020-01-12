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

void build_table(huff_node* tree_node, code table[], code code)
{         
    if(is_leaf(tree_node))
    {
        table[(int) get_item(tree_node)] = code;
        return;
    }
    else
    {
        code.size++;
        code.code <<= 1;
        if(tree_node->left != NULL)
        build_table(tree_node->left, table, code);
        code.code++;
        if(tree_node->right != NULL)
        build_table(tree_node->right, table, code);
    }        
}

int get_trash_size(code table[], int frequency[])
{
    int i;
    long long int count = 0;

    for(i = 0; i < 256; i++)
    {
        if(frequency[i] > 0)
        {
            count += table[i].size * frequency[i];
        }
    }

    count = (8 - (count % 8));

    return count;
}

void get_tree_size(huff_node *tree_root, int *count)
{
    if(tree_root != NULL)
    {
        if(is_leaf(tree_root) && (get_item(tree_root) == '*' || get_item(tree_root) == '\\'))
        {
            *count = *count + 1;    
        }

        *count = *count + 1;
        get_tree_size(tree_root->left, count);
        get_tree_size(tree_root->right, count);
    }
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
    short buffer_size = 0, caractere;
    unsigned char buffer = 0; 

    unsigned short int aux, code_tmp = 0;
    
    FILE *fileIn, *fileOut;
    fileIn = fopen(fileInPath, "r");
    fileOut = fopen(fileOutPath, "w");

    fprintf(fileOut, "%c%c", header[0], header[1]);
    print_pre_order(tree_root, fileOut);        

    while((caractere = getc(fileIn)) != EOF)
    {        
        if((table[caractere].size + buffer_size) <= 8)
        {
            buffer <<= table[caractere].size;
            buffer = buffer | table[caractere].code;
            buffer_size += table[caractere].size;
        }        
        else 
        {
            aux = table[caractere].size;                         
            buffer <<= (8 - buffer_size);
            code_tmp = table[caractere].code >> (table[caractere].size - (8 - buffer_size));
            aux -= (8 - buffer_size);            
            buffer = buffer | code_tmp;
            
            fprintf(fileOut, "%c", buffer);
            buffer = 0;
                    
            if((table[caractere].size - aux) > 8)
            {                                    
                code_tmp = table[caractere].code << 16 - (table[caractere].size - (8 - buffer_size));                    
                buffer = code_tmp >> 8;
                fprintf(fileOut, "%c", buffer);
                buffer = 0;
                aux -= 8;
            }                                

            buffer_size = aux;                

            code_tmp = table[caractere].code << (16 - buffer_size);
            code_tmp >>= (16 - buffer_size);
            buffer = code_tmp;                       
        }
        
        if(buffer_size == 8)
        {            
            fprintf(fileOut, "%c", buffer);
            buffer = 0;
            buffer_size = 0;
        }
    }    

    if(buffer_size > 0 && buffer_size < 8)
    {         
        buffer <<= (header[0] >> 5);        
        fprintf(fileOut, "%c", buffer); 
        buffer = 0;
        buffer_size = 0;
    }

    fclose(fileIn);
    fclose(fileOut);
}

void compress(char fileInPath[], char fileOutPath[])
{
    int frequency[256], trashsize = 0, treesize = 0;
    memset(frequency, 0, 256 * sizeof(int));

    huff_node *root = create_treefromfile(fileInPath, frequency);

    if(is_leaf(root)){
        unsigned char *ast = (unsigned char*) malloc(sizeof(unsigned char));
        *ast = '*';

        huff_node *new_root = create_huffman_node((void *) ast, root->freq);
        
        root = place_tree_node(new_root, root, NULL);   
    }

    code table[256], startcode;
    startcode.code = startcode.size = 0;
    memset(table, 0, 256 * sizeof(code));

    build_table(root, table, startcode);

    trashsize = get_trash_size(table, frequency);

    get_tree_size(root, &treesize);

    unsigned char *header = create_header(trashsize, treesize);

    create_out_file(fileInPath, fileOutPath, header, table, root);
}