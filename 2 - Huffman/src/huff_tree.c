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
        if((c=='*' || c=='\\') && is_leaf(tree_root)) fprintf(file, "\\%c", c);
        else fprintf(file, "%c", c);
        print_pre_order(tree_root->left, file);
        print_pre_order(tree_root->right, file);
    }    
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
        build_table(tree_node->left, table, code);
        code.code++;
        build_table(tree_node->right, table, code);
    }        
}

void get_tree_size(huff_node *tree_root, int *count)
{
    if(tree_root != NULL)
    {
        *count = *count + 1;
        get_tree_size(tree_root->left, count);
        get_tree_size(tree_root->right, count);
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