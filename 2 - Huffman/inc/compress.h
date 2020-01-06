#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huff_tree.h"
#include "priority_queue.h"

#ifndef COMPRESS_H
#define COMPRESS_H

/* Begin COMPRESS functions */

/** @param filePath: the file path for get frequency of the caracters */
/** @param freq: the array to fil with the frequency of each character */
/** @return returns the requested new huffman tree */
huff_node *create_treefromfile(char filePath[], int frequency[]);


/** @param fileInPath: the file path to read file to compress */
/** @param fileOutPath: the file path to write new file compressed */
/** @param header:  the header for the compressed file */
/** @param table: the table with size and new code */
/** @param tree_root: the huffman tree */
/** @return returns the requested new huffman tree */
void create_out_file(char fileInPath[], char fileOutPath[], unsigned char *header, code table[], huff_node *tree_root);

/** @param trashsize: the trash size of file */
/** @param treesize: amount of nodes of the huffman tree */
/** @return returns the header for the compressed file */
unsigned char *create_header(int trashsize, int treesize);

/** @param fileInPath: the file path to read file to compress */
/** @param fileOutPath: the file path to write new file compressed */
void compress(char fileInPath[], char fileOutPath[]);

/* End COMPRESS functions */

#endif /* COMPRESS_H */