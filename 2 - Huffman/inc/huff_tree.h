#ifndef HUFF_STRUCT_H
#define HUFF_STRUCT_H

typedef struct huff_node huff_node;

struct huff_node{
    unsigned char item; // the caractere (char) that will be stored at this node
    long long int freq; // frequency of the caractere
    huff_node *next; // pointer for the next node list
    huff_node *left; // pointer for the left subtree of huffman
    huff_node *right; // pointer for the right subtree of huffman
};

huff_node *create_huffman_node(unsigned char item, long long int freq, huff_node *left, huff_node* right); // create a node of huffman tree and return it

#endif /* HUFF_STRUCT_H */