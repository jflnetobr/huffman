#ifndef BST_H
#define BST_H

/* Begin BST Tree Struct */

typedef struct binary_search_tree binary_search_tree;

struct binary_search_tree {
    int item; // the number (integer) that will be stored at this node
    binary_search_tree *left; // pointer for the left subtree
    binary_search_tree *right; // pointer for the right subtree
};

/* End BST Tree Struct */

/* Begin BST Tree functions */

/** @return returns a empty binary tree (pointer for NULL) */
binary_search_tree* create_empty_binary_search_tree();

/** @param item: the number that will be stored in the binary tree being created */
/** @param left: the left subtree of the binary tree being created */
/** @param right: the right subtree of the binary tree being created */
/** @return returns the requested new binary tree */
binary_search_tree* create_binary_search_tree(int item, binary_search_tree *left, binary_search_tree *right);

/** @param item: the number that will be stored in the passed binary search tree (param bt) */
/** @param bt: the existing binary tree that will store the number (param item) */
/** @return returns the preexisting binary search tree (param bt) whith the number (param item) added */
binary_search_tree* add(binary_search_tree *bt, int item);

/** @param item: the number that will be searched in the passed binary search tree (param bt) */
/** @param bt: the existing binary search tree where the number will be searched (param item) */
/** @param count: a pointer to an integer that counts the number of comparisons */
/** @return returns the subtree that contains the searched number (param item) or NULL if the number is not found  */
binary_search_tree* search(binary_search_tree *bt, int item, int *count);

/** @param bt: the binary search tree it want to know if is empty  */
/** @return returns 1 if passed binary tree (param bt) is empty or 0 otherwise  */
int is_empty(binary_search_tree *bt);

/* Begin BST Tree functions */

#endif /* BST_H */