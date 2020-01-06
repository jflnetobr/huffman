#include "huff_tree.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/* Begin PRIORITY QUEUE Struct */

typedef struct priority_queue priority_queue;

struct priority_queue{
    huff_node *head; // pointer for the head of queue
};

/* End PRIORITY QUEUE Struct */

/* Begin PRIORITY QUEUE functions */

/** @return returns a new priority queue */
priority_queue *create_priority_queue();

/** @param queue: a pointer for a queue */
/** @return returns 1 if is empty and 0 if not */
int is_empty_queue(priority_queue *queue);

/** @param queue: a pointer for a queue */
/** @param item: the caractere that will be stored in the huffman node created */
/** @param freq: the frequency that will be stored in the huffman node created */
void enqueue_huffman_node(priority_queue *queue, huff_node *node);

/** @param queue: a pointer for a queue */
/** @return returns node dequeued */
huff_node *dequeue_huffman_node(priority_queue *queue);

/** @param queue: a pointer for a queue */
/** @return returns 1 has a next and 0 if not */
int has_next(priority_queue *queue);

/* End PRIORITY QUEUE functions */

#endif /* PRIORITY_QUEUE_H */