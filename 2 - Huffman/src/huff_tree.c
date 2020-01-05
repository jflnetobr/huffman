#include <stdio.h>
#include <stdlib.h>

#include "../inc/huff_tree.h"

/* Begin HUFF Tree functions */

/** @param item: the caractere that will be stored in the huffman node created */
/** @param freq: the frequency that will be stored in the huffman node created */
/** @param left: the left subtree of the huffman node being created */
/** @param right: the right subtree of the huffman node being created */
/** @return returns the requested new huffman node */
huff_node *create_huffman_node(unsigned char *item, long long int *freq, huff_node *left, huff_node* right)
{
    huff_node *new_huff_node = (huff_node*) malloc(sizeof(huff_node)); 
    new_huff_node->item = (void *) item; 
    new_huff_node->freq = (void *) freq; 
    new_huff_node->left = left;
    new_huff_node->right = right;
    return new_huff_node;    
}

/* End HUFF Tree functions */