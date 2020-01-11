HUFF = inc/huff_tree.h src/huff_tree.c
QUEUE = inc/priority_queue.h src/priority_queue.c
MAIN = src/main.c
COMPRESS = src/compress.c
DECOMPRESS = src/decompress.c

compile_huffman:
	gcc $(HUFF) $(QUEUE) $(COMPRESS) $(DECOMPRESS) $(MAIN) -o huffman -g