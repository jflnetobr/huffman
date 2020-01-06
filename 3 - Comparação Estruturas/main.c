#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "inc/AVL.h"
#include "inc/BST.h"

void header(){
    printf("|===============================|\n");
    printf("|Q. DE ELEMENTOS |BST    |AVL   |\n");
    printf("|===============================|\n");
}

void main(){
    int i, j, num, start = 1, maxtest = (int)pow(2, 12), acum_avl = 0, acum_bst = 0;

    binary_tree_avl *avl = create_empty_binary_tree_avl();
    binary_search_tree *bst = create_empty_binary_search_tree();
            
    FILE *file;    
    file = fopen("compare_and_plot.txt", "w");
    
    srand(time(NULL));

    header();

    for(i = 1; i <= (log(maxtest) / log(2)); i++){
        acum_avl = acum_bst = 0;

        for(j = start; j <= (int)pow(2, i); j++){
            bst = add(bst, j);
            avl = add_avl(avl, j);          
        }

        start = j;
        j = 0;
        
        while(j < (maxtest / 10))        
        {
            num = rand() % (int)pow(2, i);
                
            search(bst, num, &acum_bst);
            search_avl(avl, num, &acum_avl);
            j++;        
        }   
        
        acum_avl /= j;
        acum_bst /= j;

        printf("|%d\t\t |%d\t |%d\t|\n", start - 1, acum_bst, acum_avl);
        
        fprintf(file, "%d;%d;%d\n", start - 1, acum_bst, acum_avl);
    }
    printf("|===============================|\n");
    fclose(file);
    return;
}