HUFF = ../2\ -\ Huffman/inc/huff_tree.h ../2\ -\ Huffman/src/huff_tree.c
QUEUE = ../2\ -\ Huffman/inc/priority_queue.h ../2\ -\ Huffman/src/priority_queue.c
COMPRESS = ../2\ -\ Huffman/src/compress.c ../2\ -\ Huffman/inc/compress.h
DECOMPRESS = ../2\ -\ Huffman/src/decompress.c ../2\ -\ Huffman/inc/decompress.h
TEST = test.c 

compile_test:
	gcc $(HUFF) $(QUEUE) $(COMPRESS) $(DECOMPRESS) $(TEST) -lcunit -o test -g
