#include <stdio.h>
#include <stdlib.h>

#include "../inc/priority_queue.h"

/* Begin Priority Queue functions */

/** @return returns a new priority queue */
priority_queue *create_priority_queue()
{
    priority_queue *new_queue = (priority_queue*) malloc(sizeof(priority_queue));
    new_queue->head = NULL;
    return new_queue;
}

/** @param queue: a pointer for a queue */
/** @return returns 1 if is empty and 0 if not */
int is_empty_queue(priority_queue *queue)
{
    return (queue->head == NULL);
}

/** @param queue: a pointer for a queue */
/** @param item: the caractere that will be stored in the huffman node created */
/** @param freq: the frequency that will be stored in the huffman node created */
void enqueue_huffman_node(priority_queue *queue, unsigned char *item, long long int *freq)
{

    huff_node *new_huff_node = create_huffman_node(item, freq, NULL, NULL);

    if ((is_empty_queue(queue)) || (*freq < * (int *) queue->head->freq)) 
    {
        new_huff_node->next = queue->head;
        queue->head = new_huff_node;
    } 
    else 
    {
        huff_node *current = queue->head;

        while ((current->next != NULL) && (* (int *)current->next->freq < *freq)) {
            current = current->next;
        }
        new_huff_node->next = current->next;
        current->next = new_huff_node;
    }
}

/** @param queue: a pointer for a queue */
/** @return returns node dequeued */
huff_node *dequeue_huffman_node(priority_queue *queue)
{
    if (is_empty_queue(queue))
    {
        return NULL;
    }
    else 
    {
        huff_node *node = queue->head;
        queue->head = queue->head->next;
        node->next = NULL;
        return node;
    }
}

/* End Priority Queue functions */