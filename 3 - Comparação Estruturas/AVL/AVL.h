typedef struct binary_tree_avl binary_tree_avl;

struct binary_tree_avl {
    int item; // the number (integer) that will be stored at this node
    int h; // height of the node
    binary_tree_avl *left; // pointer for the left subtree
    binary_tree_avl *right; // pointer for the right subtree
};

/* AVL ADT */

binary_tree_avl* create_empty_binary_tree_avl(); // create a empty binary tree 
binary_tree_avl* create_binary_tree_avl(int item, binary_tree_avl *left, binary_tree_avl *right); // create a binary tree whith a given item and subtrees
binary_tree_avl* add_avl(binary_tree_avl *bt, int item); // add a number (node) in a AVL tree
binary_tree_avl* search_avl(binary_tree_avl *bt, int item, int *count); // search a number in a binary search tree
int is_empty_avl(binary_tree_avl *bt);  // check if the binary tree is empty
int height_avl(binary_tree_avl *bt); // returns the height of a node
int balance_factor_avl(binary_tree_avl *bt); // returns the balance factor of a tree or subtree
binary_tree_avl* rotate_left_avl(binary_tree_avl *bt); // left rotation function (AVL)
binary_tree_avl* rotate_right_avl(binary_tree_avl *bt); // right rotation function (AVL)