#include <stdio.h>
#include <stdlib.h>

#include "../inc/BST.h"
 
binary_search_tree* create_empty_binary_search_tree()
{
    return NULL;
}

binary_search_tree* create_binary_search_tree(int item, binary_search_tree *left, binary_search_tree *right)
{
    binary_search_tree *new_binary_search_tree = (binary_search_tree*) malloc(sizeof(binary_search_tree));
    new_binary_search_tree->item = item;
    new_binary_search_tree->left = left;
    new_binary_search_tree->right = right;
    return new_binary_search_tree;
}
 
binary_search_tree* add(binary_search_tree *bt, int item)
{
    if (bt == NULL) 
    {
        bt = create_binary_search_tree(item, NULL, NULL);
    } 
    else if (bt->item > item) 
    {
        bt->left = add(bt->left, item);
    } 
    else
    {
        bt->right = add(bt->right, item);
    }
    return bt;
}

binary_search_tree *search(binary_search_tree *bt, int item, int *count)
{
    if ((bt == NULL) || (bt->item == item)) 
    {
        *count = *count + 1;
        return bt;
    } 
    else if (bt->item > item) 
    {
        *count = *count + 1;
        return search(bt->left, item, count);
    } 
    else 
    {
        *count = *count + 1;   
        return search(bt->right, item, count);
    }
}

int is_empty(binary_search_tree *bt)
{
    return (bt == NULL);
}