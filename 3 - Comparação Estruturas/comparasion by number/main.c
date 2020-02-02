#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "../inc/AVL.h"
#include "../inc/BST.h"

void header(){
    printf("|===============================|\n");
    printf("|NÚMERO SORTEADO |BST    |AVL   |\n");
    printf("|===============================|\n");
}

void main(){
    int i, num, comp_bst, comp_avl, maxsize = 4096;

    binary_tree_avl *avl = create_empty_binary_tree_avl();
    binary_search_tree *bst = create_empty_binary_search_tree();
            
    FILE *file;    
    file = fopen("compare_and_plot.txt", "w");
    
    srand(time(NULL));

    header();

    for(i = 1; i <= maxsize; i++){
        num = rand() % maxsize;

        bst = add(bst, num);
        avl = add_avl(avl, num);
    }

    for(i = 1; i <= 100; i++){
        num = rand() % maxsize;

        comp_bst = comp_avl = 0;

        search(bst, num, &comp_bst);
        search_avl(avl, num, &comp_avl);

        printf("|%d\t\t |%d\t |%d\t|\n", num, comp_bst, comp_avl);
        
        fprintf(file, "%d;%d;%d\n", num, comp_bst, comp_avl);
    }

    printf("|===============================|\n");
    fclose(file);
    return;
}