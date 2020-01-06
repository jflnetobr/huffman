#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"
#include "../inc/compress.h"

void main(){ 
    compress("teste.txt", "out.txt");

    return;
}