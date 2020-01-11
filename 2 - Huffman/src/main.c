#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"
#include "../inc/compress.h"
#include "../inc/decompress.h"

void remove_substring(char *string, char *sub) 
{
    char *match = string;
    int len = strlen(sub);
    while((match = strstr(match, sub))) 
    {
        *match = '\0';
        strcat(string, match + len);
        match++;
    }
}

void clear_screen()
{
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif
}

void help()
{
    printf("Comandos:\n-c <caminho do arquivo> para comprimir\n-d <caminho do arquivo> para descomprimir\n-o <caminho do arquivo> após o -c ou -d, para escolher o local onde vai ser salvo o arquivo\n-h para informações\n");
}

void main(int argc, char **argv)
{  
    if( argc >= 2 )
    {
        if(argv[1][0] == '-')
        {
            if(argv[1][1] == 'c')
            {
                if(argv[2])
                {
                    if(argv[3])
                    {
                        if(argv[3][0] == '-')
                        {
                            if(argv[3][1] == 'o')
                            {
                                if(argv[4])
                                {
                                    compress(argv[2], argv[4]);
                                } 
                                else 
                                {
                                    clear_screen();
                                    printf("O Caminho de saída do arquivo não foi informado!\n");
                                    help();
                                }
                            } 
                            else 
                            {
                                clear_screen();
                                printf("Entrada inválida!\n");
                                help();
                            }
                        } 
                        else 
                        {
                            clear_screen();
                            printf("Entrada inválida!\n");
                            help();
                        }
                    } 
                    else 
                    {
                        char string[250], substring[10];
                        strcpy(string,  argv[2]);  
                        strcpy(substring,  ".huff");   
                        strcat(string, substring);
                        compress(argv[2], string);
                    }
                } 
                else 
                {
                    clear_screen();
                    printf("O Caminho do arquivo não foi informado!\n");
                    help();
                }
            } 
            else if(argv[1][1] == 'd')
            {
                if(argv[2])
                {
                    if(argv[3])
                    {
                        if(argv[3][0] == '-')
                        {
                            if(argv[3][1] == 'o')
                            {
                                if(argv[4])
                                {
                                    decompress(argv[2], argv[4]);
                                } 
                                else 
                                {
                                    clear_screen();
                                    printf("O Caminho de saída do arquivo não foi informado!\n");
                                    help();
                                }
                            } 
                            else 
                            {
                                clear_screen();
                                printf("Entrada inválida!\n");
                                help();
                            }
                        } 
                        else 
                        {
                            clear_screen();
                            printf("Entrada inválida!\n");
                            help();
                        }
                    }
                    else 
                    {
                        char *string;
                        strcpy(string, argv[2]);
                        remove_substring(string, ".huff");
                        decompress(argv[2], string);
                    }
                } 
                else 
                {
                    clear_screen();
                    printf("O Caminho do arquivo não foi informado!\n");
                    help();
                }
            } 
            else if(argv[1][1] == 'h')
            {
                clear_screen();
                help();
            } 
            else 
            {
                clear_screen();
                printf("Entrada inválida!\n");
                help();
            }
        } 
        else 
        {
            clear_screen();
            printf("Entrada inválida!\n");
            help();
        }
    }
    else
    {
        clear_screen();
        printf("Sem argumentos!\n");
        help();
    }

    return;
}