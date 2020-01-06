#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/huff_tree.h"

huff_node *create_huffman_node(void *item, long long int freq)
{
    huff_node *new_huff_node = (huff_node*) malloc(sizeof(huff_node)); 

    new_huff_node->item = item;
    new_huff_node->freq = freq;
    new_huff_node->left = NULL;
    new_huff_node->right = NULL;
    new_huff_node->next = NULL;
    return new_huff_node;
}

huff_node *place_tree_node(huff_node* node, huff_node* left, huff_node* right)
{    
    node->right = right;
    node->left = left;

    return node;
}

int is_leaf(huff_node* node)
{
    return (node->left==NULL && node->right==NULL);
}

unsigned char get_item(huff_node* node)
{
    if(node!=NULL)
    {
        unsigned char *item = (unsigned char*) node->item;
        return *item;
    }
    else
    {
        return NULL;
    }
}

void print_pre_order(huff_node* tree_root)
{
    if(tree_root != NULL)
    {
        unsigned char c = get_item(tree_root);
        if((c=='*' || c=='\\') && is_leaf(tree_root)) printf("\\%c", c);
        else printf("%c", c);
        print_pre_order(tree_root->left);
        print_pre_order(tree_root->right);
    }    
}

void build_table(huff_node* tree_node, code table[], code code)
{         
    if(is_leaf(tree_node))
    {
        table[get_item(tree_node)] = code;
        return;
    }
    else
    {
        code.size++;
        code.code <<= 1;
        build_table(tree_node->left, table, code);
        code.code++;
        build_table(tree_node->right, table, code);
    }        
}