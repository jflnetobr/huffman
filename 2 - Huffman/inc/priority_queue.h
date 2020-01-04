#include "huff_tree.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct huff_node huff_node;
typedef struct priority_queue priority_queue;

struct priority_queue{
    huff_node *head;
};

priority_queue *create_priority_queue(); // create a priority queue and return it
int is_empty_queue(priority_queue *queue); // check if queue if empty
void enqueue_huffman_node(priority_queue *queue, unsigned char item, long long int freq); // enqueue a huffman node in queue
huff_node *dequeue_huffman_node(priority_queue *queue); // dequeue a huffman node of queue and return it

#endif /* PRIORITY_QUEUE_H */