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

void set_subtree(huff_node* node, huff_node* subtree, int dir)
{        
    if(dir)
    {
        node->right = subtree;
    }
    else
    {
        node->left = subtree;
    }
}

int is_leaf(huff_node* node)
{
    return ((node->left == NULL) && (node->right == NULL));
}

unsigned char get_item(huff_node* node)
{
    unsigned char *item = (unsigned char*) node->item;

    return *item;
}

void print_pre_order(huff_node* tree_root, FILE *file)
{
    if(tree_root != NULL)
    {
        unsigned char c = get_item(tree_root);
        
        if((c=='*' || c=='\\') && is_leaf(tree_root))
        {
            fprintf(file, "\\%c", c);
        }
        else
        {
            fprintf(file, "%c", c);
        }

        print_pre_order(tree_root->left, file);
        print_pre_order(tree_root->right, file);
    }    
}