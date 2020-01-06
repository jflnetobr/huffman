#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/huff_tree.h"
#include "inc/priority_queue.h"

void main(){
    int i, c;
    int freq[256];
    memset(freq,0,256*sizeof(int));

    priority_queue *pq = create_priority_queue();    
    huff_node *node1, *node2, *root;

    FILE *file, *stream;    
    file = fopen("teste.txt", "r");
    stream = file;

    while((c = getc(stream)) != EOF)
    {
        freq[c]++;
    }

    for(i=0;i<256;i++)
    { 
        if(freq[i]>0) 
        {            
            unsigned char *item = (unsigned char*) malloc(sizeof(unsigned char));
            *item = i;
            enqueue_huffman_node(pq, create_huffman_node((void*) item,freq[i]));
        }
    }       
    
    unsigned char *ast = (unsigned char*) malloc(sizeof(unsigned char));
    *ast = '*';

    while(has_next(pq))
    {
        node1 = dequeue_huffman_node(pq);
        node2 = dequeue_huffman_node(pq);

        root = create_huffman_node((void *) ast, node1->freq + node2->freq);
        
        root = place_tree_node(root,node1,node2);        

        enqueue_huffman_node(pq,root);
    }

    root = dequeue_huffman_node(pq);

    print_pre_order(root);
    
    fclose(file);

    return;
}