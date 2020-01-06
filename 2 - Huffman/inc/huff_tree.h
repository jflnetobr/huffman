#ifndef HUFF_STRUCT_H
#define HUFF_STRUCT_H

/* Begin HUFF Struct */

typedef struct code code;
typedef struct huff_node huff_node;

struct code{
    unsigned char code; // the binary code of an item
    unsigned char size; // the size of the code
};

struct huff_node{
    void *item; // the data that will be stored at this node
    long long int freq; // frequency of the caractere
    huff_node *next; // pointer for the next node list
    huff_node *left; // pointer for the left subtree of huffman
    huff_node *right; // pointer for the right subtree of huffman
};

/* End HUFF Struct */

/* Begin HUFF Tree functions */

/** @param item: the item that will be stored at the huffman node created */
/** @param freq: the frequency of the item that will be stored at the huffman node created */
/** @return returns the requested new huffman node */
huff_node *create_huffman_node(void *item, long long int freq); // create a node of huffman tree and return it

/** @param node: the node that will be the root of the tree to be created */
/** @param left: the left subtree of the tree to be created */
/** @param right: the right subtree of the tree to be created */
/** @return returns the requested tree of huffman nodes */
huff_node *place_tree_node(huff_node* node, huff_node* left, huff_node* right);

/** @param node: the node that will be tested if is a leaf of the tree */
/** @return returns 1 if the passed node is a leaf or 0 if isn't */
int is_leaf(huff_node* node);

/** @param node: the node that is desired to know the stored item */
/** @return returns the item stored at the node or NULL if the node is NULL */
unsigned char get_item(huff_node* node);

/** @param tree_root: the root of the tree that is desired to pre-order traversals */
void print_pre_order(huff_node* tree_root);

/** @param tree_node: the node that is desired to get the item and frequency of this item */
/** @param table: an array representing a table that lists items in ASCII code and Huffman code */
/** @param code: the code we want to store */
void build_table(huff_node* tree_node, code table[], code code);

/* End HUFF Tree functions */

#endif