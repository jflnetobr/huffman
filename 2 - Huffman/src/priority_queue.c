#include "../inc/priority_queue.h"

priority_queue *create_priority_queue()
{
    priority_queue *new_queue = (priority_queue*) malloc(sizeof(priority_queue));
    
    new_queue->head = NULL;
    
    return new_queue;
}

int is_empty_queue(priority_queue *queue)
{
    return (queue->head == NULL);
}

int has_next(priority_queue *queue)
{
    if(queue->head == NULL)
    {
        return 0;
    } 
    else if(queue->head->next != NULL)
    {
        return 1;
    }
}

void enqueue_huffman_node(priority_queue *queue, huff_node *node)
{
    if ((is_empty_queue(queue)) || (node->freq <= queue->head->freq)) 
    {
        node->next = queue->head;
        queue->head = node;
    } 
    else 
    {
        huff_node *current = queue->head;

        while ((current->next != NULL) && (current->next->freq < node->freq)) {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }
}

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