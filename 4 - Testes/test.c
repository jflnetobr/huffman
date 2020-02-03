#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../2 - Huffman/inc/huff_tree.h"
#include "../2 - Huffman/inc/priority_queue.h"
#include "../2 - Huffman/inc/compress.h"
#include "../2 - Huffman/inc/decompress.h"

int init_suite(void) {
    return 0;
}

int clean_suite(void) { 
    return 0; 
}

void test_set_void_pointer(){
    /* Using 'set_void_pointer' */
    void *item = set_void_pointer('*');
    /* Adding the item into a node */
    huff_node *root = create_huffman_node(item,21);
    /* Checking if it was correctly stored */
    CU_ASSERT_EQUAL(get_item(root),'*');
}

void test_create_huffman_node(){
    void *item = set_void_pointer('*');
    /* Adding the item '*' with a frequency of 21 */
    huff_node *root = create_huffman_node(item,21);
    /* Checking if left, right and next points to NULL */ 
    CU_ASSERT_EQUAL(NULL,root->left);
    CU_ASSERT_EQUAL(NULL,root->right);
    CU_ASSERT_EQUAL(NULL,root->next);
    /* Checking if the frequency and the item were correctly stored */
    CU_ASSERT_EQUAL(21,root->freq);
    CU_ASSERT_EQUAL('*',get_item(root));
}


void test_place_tree_node(){
    void *item = set_void_pointer('*');
    /* Creating 3 nodes */
    huff_node *root = create_huffman_node(item,21);
    huff_node *node_left = create_huffman_node (item,9);
    huff_node *node_right = create_huffman_node (item,12);
    /* Placing the nodes as subnodes of the root node */
    place_tree_node (root,node_left,node_right);
    /* Checking if the item and frequency were correctly stored */
    CU_ASSERT_EQUAL(get_item(root),'*');
    CU_ASSERT_EQUAL(root->freq,21);
    CU_ASSERT_EQUAL(get_item(root->right),'*');
    CU_ASSERT_EQUAL(root->left->freq,9);
    CU_ASSERT_EQUAL(get_item(root->right),'*');
    CU_ASSERT_EQUAL(root->right->freq,12);
}

void test_is_leaf(){
    void *item = set_void_pointer('*');
    /* Creating 3 nodes*/
    huff_node *root = create_huffman_node(item,55);
    huff_node *node_left = create_huffman_node (item,30);
    huff_node *node_right = create_huffman_node (item,25);
    /* Placing the nodes as subnodes of the root node */
    place_tree_node (root,node_left,node_right);
    /* Checking 'is_leaf' on the root */
    CU_ASSERT_EQUAL(is_leaf(root),0);
    /* Checking 'is-leaf' on the leafs */
    CU_ASSERT_EQUAL(is_leaf(root->left),1);
    CU_ASSERT_EQUAL(is_leaf(root->right),1);
}

void test_print_pre_order(){
    unsigned char c_out, c_in;

    short filesize = (short) get_filesize("tree.txt");

    FILE *fileIn = fopen("tree.txt", "r");
    FILE *fileOut = fopen("treeout.txt", "w");

    huff_node *root = mount_tree(fileIn, &filesize);

    rewind(fileIn);

    print_pre_order(root, fileOut);

    fclose(fileOut);

    fileOut = fopen("treeout.txt", "r");

    while((fscanf(fileIn, "%c", &c_in) != EOF) && (fscanf(fileOut, "%c", &c_out) != EOF))
    {
        CU_ASSERT_EQUAL(c_out, c_in);
    } 

    fclose(fileIn);
    fclose(fileOut);
}

 void test_create_priority_queue(){
    /* Creating a empty queue */
    priority_queue *queue = create_priority_queue();
    /* Testing if the head of the queue points to NULL */
    CU_ASSERT_EQUAL(queue -> head,NULL);
    free(queue);
 }
 
 void test_is_empty_queue(){
    /* Creating an empty queue */ 
    priority_queue *queue = create_priority_queue();
    /* Checking if the queue is empty with the 'is_empty_queue' function */
    CU_ASSERT_EQUAL(is_empty_queue(queue),1);
    free(queue);
 }

 void test_has_next(){
    /* Creating a empty queue */
    priority_queue *queue = create_priority_queue();
    /* Because the queue is empty, it must return '0' */
    CU_ASSERT_EQUAL(has_next(queue),0);
    free(queue);
}

 void test_get_item(){
     /* Adding a random item to the queue */
    unsigned char random = rand() % 255 ;
    priority_queue *queue = create_priority_queue();
    huff_node *new_node;
    void *item = set_void_pointer(random);
    enqueue_huffman_node(queue,create_huffman_node(item,1));
    new_node = dequeue_huffman_node(queue);
    /* Checking if the function returns the item correctly */
    CU_ASSERT_EQUAL(get_item(new_node),random);
 }

void test_enqueue_dequeue() {
    int i;
    unsigned char random[255];
    priority_queue *queue = create_priority_queue();
    huff_node *new_node;
    for(i=255;i>=0;i--)
    {
        /* Adding random itens to the queue */
        random[i] =  rand() % 255 ;
        void *item = set_void_pointer(random[i]);
        enqueue_huffman_node(queue, create_huffman_node((void*) item, i));
    }
    for(i=0;i<256;i++)
    {
        /* Removing all itens of the queue */ 
        new_node = dequeue_huffman_node(queue);
        /* Checking if the item was correctly stored */ 
        CU_ASSERT_EQUAL(get_item(new_node),random[i]);
    }
    /* Testing if 'next' node is NULL */
    CU_ASSERT_EQUAL(has_next(queue),0);
    /* Testing if is was completely dequeued */
    CU_ASSERT_EQUAL(queue->head,NULL);
    free(queue);
}

int main (void) {
    srand(time(NULL));
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())return CU_get_error();
    
    pSuite = CU_add_suite("Basic_Test", init_suite, clean_suite);
    
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Priority Queue Creation...\n\n", test_create_priority_queue))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'is_empty_queue' Function ...\n\n", test_is_empty_queue))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'has_next' Function ...\n\n", test_has_next))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'get_item' Function ...\n\n", test_get_item))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing Enqueue and Dequeue Functions ...\n\n", test_enqueue_dequeue))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing HuffNode Creation ...\n\n", test_create_huffman_node))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'place_tree_node' Function ...\n\n", test_place_tree_node))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'is_leaf' Function ...\n\n", test_is_leaf))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'print_pre_order' Function ...\n\n", test_print_pre_order))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "\n\n... Testing 'set_void_pointer' Function ...\n\n", test_set_void_pointer))) {
    CU_cleanup_registry();
    return CU_get_error();
    }

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}