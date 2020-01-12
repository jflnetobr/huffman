#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huff_tree.h"
#include "priority_queue.h"

#ifndef DECOMPRESS_H
#define DECOMPRESS_H

/* Begin DECOMPRESS functions */

/** @param c: the unsigned char that is desired to know if have the bit "i" set*/
/** @param i: the bit that is desired to know if is set at c char */
int is_bit_i_set(unsigned char c, int i);

/** @param filePath: the path of the file that is desired to know the size */
/** @return returns file size in bytes */
long long int get_filesize(char filePath[]);

/** @param fileIn: a pointer to the .huff file to decompress  */
/** @param treesize: the current tree size */
/** @return returns the root of the new huffman tree created */
huff_node *mount_tree(FILE *fileIn, short int *treesize);

/** @param fileIn: a pointer to the .huff file to decompress */
/** @param fileOt: a pointer to the decompressed file */
/** @param tree: the root of the huffman tree of the compressed file */
/** @param tree: the root of the huffman tree of the compressed file */
/** @param trashsize: the size of the trash at the compressed file (last bits) */
/** @param filesize: the size of the compressed file (minus the header size) */
void fill_file(FILE *fileIn, FILE *fileOut, huff_node *tree, short int trashsize, long long int file_size);

/** @param fileInPath: the file path to read the .huff file to decompress */
/** @param fileOutPath: the file path to write the decompressed file */
void decompress(char fileInPath[], char fileOutPath[]);

/* End DECOMPRESS functions */

#endif /* DECOMPRESS_H */