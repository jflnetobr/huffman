#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huff_tree.h"
#include "priority_queue.h"

#ifndef COMPRESS_H
#define COMPRESS_H

typedef struct code code;

struct code{
    unsigned short int code; // the binary code of an item
    unsigned short int size; // the size of the code
};

/* Begin COMPRESS functions */

/** @param filePath: the file path for get frequency of the caracters */
/** @param freq: the array to fill with the frequency of each character */
/** @return returns the requested new huffman tree */
huff_node *create_treefromfile(char filePath[], int frequency[]);

/** @param tree_node: the node that is desired to get the item and frequency of this item */
/** @param table: an array representing a table that lists items in ASCII code and Huffman code */
/** @param code: the code we want to store */
void build_table(huff_node* tree_node, code table[], code code);

/** @param table: the table with new code for every caracter */
/** @param frequency: the frequency of each character from file */
/** @return returns the trash size */
int get_trash_size(code table[], int frequency[]);

/** @param tree_root: the root of the tree is desired get size */
/** @param count: pointer to return count */
void get_tree_size(huff_node *tree_root, int *count);

/** @param trashsize: the file trash size */
/** @param treesize: the size of the huffman tree */
/** @return returns the header for the compressed file */
unsigned char *create_header(int trashsize, int treesize);

/** @param fileInPath: the file path to read file to compress */
/** @param fileOutPath: the file path to write new file compressed */
/** @param header:  the header for the compressed file */
/** @param table: the table with size and new code */
/** @param tree_root: the huffman tree */
void create_out_file(char fileInPath[], char fileOutPath[], unsigned char *header, code table[], huff_node *tree_root);

/** @param fileInPath: the file path to read file to compress */
/** @param fileOutPath: the file path to write new file compressed */
void compress(char fileInPath[], char fileOutPath[]);

/* End COMPRESS functions */

#endif /* COMPRESS_H */