#include "../inc/decompress.h"

int is_bit_i_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask & c;
}

long long int get_filesize(char filePath[])
{
    FILE *file;
    file = fopen(filePath, "r");

    fseek(file, 0, SEEK_END);
    return ftell(file);              
}

huff_node *mount_tree(FILE *fileIn, short int *treesize)
{
    if(*treesize > 0)
    {         
        int flag = 0;    
        *treesize = *treesize - 1;

        unsigned char caractere = getc(fileIn);

        if(caractere == '\\')
        {
            caractere = getc(fileIn);
            *treesize = *treesize - 1;
            flag = 1;            
        }          
        
        unsigned char *aux = (unsigned char*) malloc(sizeof(unsigned char));
        *aux = caractere;
        void *pointer_void = (void *) aux;
        
        huff_node *root = create_huffman_node(pointer_void, 0);

        if(caractere == '*' && !flag)
        {                             
            set_subtree(root, mount_tree(fileIn, treesize), 0);                     
            set_subtree(root, mount_tree(fileIn, treesize), 1);
        }
        
        return root;
    }
}

void fill_file(FILE *fileIn, FILE *fileOut, huff_node *tree, short int trashsize, long long int file_size)
{    
    int i, j;
    unsigned char caractere;  
    huff_node *current = tree;  
    
    for(j = 0; j < file_size - 1; j++)
    {
        caractere = getc(fileIn);

        for(i = 7; i >= 0; i--)
        {
            if(is_bit_i_set(caractere, i))
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
            
            if(is_leaf(current))
            {
                fprintf(fileOut, "%c", get_item(current));
                current = tree;                
            }            
        }                
    }
    
    caractere = getc(fileIn);
    
    for(i = 7; i >= trashsize; i--)
    {        
        if(is_bit_i_set(caractere, i))
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
        
        if(is_leaf(current))
        {
            fprintf(fileOut, "%c", get_item(current));
            current = tree;            
        }
    }            
}

void decompress(char fileInPath[], char fileOutPath[])
{   
    FILE *fileIn, *fileOut;
    fileIn = fopen(fileInPath, "r");
    fileOut = fopen(fileOutPath, "w");

    huff_node *tree;
    
    long long int file_size = get_filesize(fileInPath);      

    short int trashsize = 0, treesize = 0;
    unsigned char buffer = getc(fileIn);
    
    trashsize = buffer >> 5;    
    buffer <<= 3;    
    buffer >>= 3;    
    treesize = buffer;
    treesize <<= 8;
    buffer = getc(fileIn);
    treesize = treesize | buffer;

    file_size -= (treesize + 2);
    
    tree = mount_tree(fileIn, &treesize);

    fill_file(fileIn, fileOut, tree, trashsize, file_size);    

    fclose(fileIn);
    fclose(fileOut); 
}
