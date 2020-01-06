#include <stdio.h>
#include <stdlib.h>

#include "../inc/AVL.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

binary_tree_avl* create_empty_binary_tree_avl()
{
    return NULL;
}

binary_tree_avl* create_binary_tree_avl(int item, binary_tree_avl *left, binary_tree_avl *right)
{
    binary_tree_avl *new_binary_tree_avl = (binary_tree_avl*) malloc(sizeof(binary_tree_avl)); 
    new_binary_tree_avl->item = item; 
    new_binary_tree_avl->left = left;
    new_binary_tree_avl->right = right;
    return new_binary_tree_avl;    
}

binary_tree_avl* add_avl(binary_tree_avl *bt, int item)
{
    if (bt == NULL) 
    {
        return create_binary_tree_avl(item, NULL, NULL);
    } 
    else if(bt->item > item)
    {
        bt->left = add_avl(bt->left, item);
    } 
    else 
    {
        bt->right = add_avl(bt->right, item);
    }

    bt->h = height_avl(bt);
    binary_tree_avl *child;

    if(balance_factor_avl(bt) == 2 || balance_factor_avl(bt) == -2)
    {
        if(balance_factor_avl(bt) == 2)
        {
            child = bt->left;
            if(balance_factor_avl(child) == -1)
            {
                bt->left = rotate_left_avl(child);
            }
            bt = rotate_right_avl(bt);
        } 
        else if(balance_factor_avl(bt) == -2) 
        {
            child = bt->right;
            if (balance_factor_avl(child) == 1) 
            {
                bt->right = rotate_right_avl(child);
            }
            bt = rotate_left_avl(bt);
        }
    }
    return bt;
}

binary_tree_avl* search_avl(binary_tree_avl *bt, int item, int *count)
{
    if ((bt == NULL) || (bt->item == item)) 
    {
        *count = *count + 1;   
        return bt;
    } 
    else if (bt->item > item) 
    {
        *count = *count + 1;   
        return search_avl(bt->left, item, count);
    }
    else 
    {
        *count = *count + 1;   
        return search_avl(bt->right, item, count);
    }
}

int is_empty_avl(binary_tree_avl *bt)
{
    return (bt == NULL);
}

int height_avl(binary_tree_avl *bt)
{
    if(bt == NULL)
    {
        return -1;
    } 
    else 
    {
        return max(height_avl(bt->left), height_avl(bt->right)) + 1;
    }
}
 
int balance_factor_avl(binary_tree_avl *bt)
{
    if (bt == NULL) 
    {
        return 0;
    } 
    else if((bt->left != NULL) && (bt->right != NULL)) 
    {
        return (bt->left->h - bt->right->h);
    } 
    else if ((bt->left != NULL) && (bt->right == NULL)) 
    {
        return (1 + bt->left->h);
    } 
    else 
    {
        return (-bt->right->h - 1);
    }
}

binary_tree_avl* rotate_left_avl(binary_tree_avl *bt)
{
    binary_tree_avl *subtree_root = NULL;
    if(bt != NULL && bt->right != NULL)
    {
        subtree_root = bt->right;
        bt->right = subtree_root->left;
        subtree_root->left = bt;
    }

    subtree_root->h = height_avl(subtree_root);
    bt->h = height_avl(bt);
    return subtree_root;
}

binary_tree_avl* rotate_right_avl(binary_tree_avl *bt)
{
    binary_tree_avl *subtree_root = NULL;
    if(bt != NULL && bt->left != NULL){
        subtree_root = bt->left;
        bt->left = subtree_root->right;
        subtree_root->right = bt;
    }

    subtree_root->h = height_avl(subtree_root);
    bt->h = height_avl(bt);
    return subtree_root;
}