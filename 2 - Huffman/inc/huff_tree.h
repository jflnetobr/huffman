#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HUFF_STRUCT_H
#define HUFF_STRUCT_H

/* Begin HUFF Struct */

typedef struct huff_node huff_node;

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
huff_node *create_huffman_node(void *item, long long int freq); // creates a huffman node with the given informations and returns it

/** @param node: the node that will be the root of the tree to be created */
/** @param left: the left subtree of the tree to be created */
/** @param right: the right subtree of the tree to be created */
/** @return returns the requested tree of huffman nodes */
huff_node *place_tree_node(huff_node* node, huff_node* left, huff_node* right); // sets the left and right subtrees of an huffman node (root of the tree)

/** @param node: the node that will receive a subtree */
/** @param subtree: the subtree that will be aggregated to the root */
/** @param right: the side of the subtree: 0 if is an left subtree, 1 if is an right subtree */
void set_subtree(huff_node* node, huff_node* subtree, int dir); // sets the left or right subtree of the given root (left or right defined by param 'dir')

/** @param node: the node that will be tested if is a leaf of the tree */
/** @return returns 1 if the passed node is a leaf or 0 if isn't */
int is_leaf(huff_node* node); // checks if a given huffman node is a leaf in the tree

/** @param node: the node that is desired to know the stored item */
/** @return returns the item stored at the node or NULL if the node is NULL */
unsigned char get_item(huff_node* node); // returns the character that corresponds to the *void stored in the huffman node

/** @param tree_root: the root of the tree that is desired to pre-order traversals */
/** @param file: the file to write the tree */
void print_pre_order(huff_node* tree_root, FILE *file); // saves an huffman tree in pre-order traversals at an given file

/* End HUFF Tree functions */

#endif