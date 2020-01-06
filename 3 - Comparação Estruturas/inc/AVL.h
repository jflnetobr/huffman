#ifndef AVL_H
#define AVL_H

/* Begin AVL Tree Struct */

typedef struct binary_tree_avl binary_tree_avl;

struct binary_tree_avl {
    int item; // the number (integer) that will be stored at this node
    int h; // height of the node
    binary_tree_avl *left; // pointer for the left subtree
    binary_tree_avl *right; // pointer for the right subtree
};

/* End AVL Tree Struct */

/* Begin AVL Tree functions */

/** @return returns a empty binary tree (pointer for NULL) */
binary_tree_avl* create_empty_binary_tree_avl();

/** @param item: the number that will be stored in the binary tree being created */
/** @param left: the left subtree of the binary tree being created */
/** @param right: the right subtree of the binary tree being created */
/** @return returns the requested new binary tree */
binary_tree_avl* create_binary_tree_avl(int item, binary_tree_avl *left, binary_tree_avl *right);

/** @param item: the number that will be stored in the passed AVL tree (param bt) */
/** @param bt: the existing binary tree that will store the number (param item) */
/** @return returns the preexisting AVL tree (param bt) whith the number (param item) added */
binary_tree_avl* add_avl(binary_tree_avl *bt, int item);

/** @param item: the number that will be searched in the passed AVL tree (param bt) */
/** @param bt: the existing AVL tree where the number will be searched (param item) */
/** @param count: a pointer to an integer that counts the number of comparisons */
/** @return returns the subtree that contains the searched number (param item) or NULL if the number is not found  */
binary_tree_avl* search_avl(binary_tree_avl *bt, int item, int *count);

/** @param bt: the AVL tree it want to know if is empty */
/** @return returns 1 if passed binary tree (param bt) is empty or 0 otherwise  */
int is_empty_avl(binary_tree_avl *bt);

/** @param bt: the node (an AVL tree root) it want to know the height */
/** @return returns the height of a given node (param bt) */
int height_avl(binary_tree_avl *bt);

/** @param bt: the node (an AVL tree root) it want to know the balance factor */
/** @return returns the balance factor of a given node (param bt) */
int balance_factor_avl(binary_tree_avl *bt);

/** @param bt: the node (an AVL tree root) it want to rotate (left) */
/** @return returns the node (param bt) after rotate (left) */
binary_tree_avl* rotate_left_avl(binary_tree_avl *bt);

/** @param bt: the node (an AVL tree root) it want to rotate (right) */
/** @return returns the node (param bt) after rotate (right) */
binary_tree_avl* rotate_right_avl(binary_tree_avl *bt);

/* End AVL Tree functions */

#endif /* AVL_H */