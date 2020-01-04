#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/* Begin Binary Search Tree functions */
 
/** @return returns a empty binary tree (pointer for NULL) */
binary_search_tree* create_empty_binary_search_tree()
{
    return NULL;
}

/** @param item: the number that will be stored in the binary tree being created */
/** @param left: the left subtree of the binary tree being created */
/** @param right: the right subtree of the binary tree being created */
/** @return returns the requested new binary tree */
binary_search_tree* create_binary_search_tree(int item, binary_search_tree *left, binary_search_tree *right)
{
    binary_search_tree *new_binary_search_tree = (binary_search_tree*) malloc(sizeof(binary_search_tree));
    new_binary_search_tree->item = item;
    new_binary_search_tree->left = left;
    new_binary_search_tree->right = right;
    return new_binary_search_tree;
}
 
/** @param item: the number that will be stored in the passed binary search tree (param bt) */
/** @param bt: the existing binary tree that will store the number (param item) */
/** @return returns the preexisting binary search tree (param bt) whith the number (param item) added */
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

/** @param item: the number that will be searched in the passed binary search tree (param bt) */
/** @param bt: the existing binary search tree where the number will be searched (param item) */
/** @param count: a pointer to an integer that counts the number of comparisons */
/** @return returns the subtree that contains the searched number (param item) or NULL if the number is not found  */
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

/** @param bt: the binary search tree it want to know if is empty  */
/** @return returns 1 if passed binary tree (param bt) is empty or 0 otherwise  */
int is_empty(binary_search_tree *bt)
{
    return (bt == NULL);
}
 
/* End Binary Search Tree functions */