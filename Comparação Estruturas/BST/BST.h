typedef struct binary_search_tree binary_search_tree;

struct binary_search_tree {
    int item; // the number (integer) that will be stored at this node
    binary_search_tree *left; // pointer for the left subtree
    binary_search_tree *right; // pointer for the right subtree
};

/* BST ADT */

binary_search_tree* create_empty_binary_search_tree(); // create a empty binary tree 
binary_search_tree* create_binary_search_tree(int item, binary_search_tree *left, binary_search_tree *right); // create a binary tree whith a given item and subtrees
binary_search_tree* add(binary_search_tree *bt, int item); // add a number (node) in a binary tree
binary_search_tree* search(binary_search_tree *bt, int item, int *count); // search a number in a binary search tree
int is_empty(binary_search_tree *bt);  // check if the binary tree is empty