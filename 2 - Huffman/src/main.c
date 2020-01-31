#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_RESET "\033[0;0m"
#define ANSI_COLOR_BOLD "\033[;1m"

#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"
#include "../inc/compress.h"
#include "../inc/decompress.h"

char *convert_size(long long int size)
{
    char *size_type;
    float size_float = (float) size;    
    
    if (size >= 1000000000)
    {
        size_float /= 1000000000;
        sprintf (size_type, "%.2f", size_float);     
        strcat(size_type, " GB");
        return  size_type;
    }
    else if (size >= 1000000)
    {
        size_float /= 1000000;
        sprintf (size_type, "%.2f", size_float);     
        strcat(size_type," MB");
        return  size_type;
    }
    else if(size >= 1000)
    {
        size_float /= 1000;
        sprintf (size_type, "%.2f", size_float);     
        strcat(size_type," KB");
        return  size_type;
    }    
    else
    {        
        sprintf (size_type, "%.0f", size_float);     
        strcat(size_type," Bytes");
        return  size_type;
    }
}

void print_file_sizes(char fileIn[], char fileOut[])
{
    long long int initial_size = get_filesize(fileIn);
    long long int end_size = get_filesize(fileOut);

    char *initial_size_string = convert_size(initial_size);

    printf(ANSI_COLOR_GREEN " - Arquivo comprimido com sucesso \n" ANSI_COLOR_RESET); 
    printf(" - Arquivo ");
    printf(ANSI_COLOR_BOLD"%s "ANSI_COLOR_RESET, fileIn);
    printf("comprimido para ");
    printf(ANSI_COLOR_BOLD"%s \n"ANSI_COLOR_RESET, fileOut);    
    
    printf("-------------------------------------------------\n - Tamanho do arquivo original: ");
    printf(ANSI_COLOR_BOLD"%s\n"ANSI_COLOR_RESET, initial_size_string);

    char *end_size_string = convert_size(end_size);

    printf(" - Tamanho do arquivo comprimido: ");
    printf(ANSI_COLOR_BOLD"%s\n"ANSI_COLOR_RESET, end_size_string);                                    

    printf("-------------------------------------------------\n");
                                            
    float percent = (float) end_size/initial_size;
    percent -= 1;
    if(initial_size >= end_size)
    {
        percent *= -100;
        printf(" - Arquivo compactado ");
        printf(ANSI_COLOR_BOLD"%.2f%% MENOR "ANSI_COLOR_RESET,percent);   
        printf("que o original\n");
    }
    else
    {
        percent *= 100;
        printf(" - Arquivo compactado ");
        printf(ANSI_COLOR_BOLD"%.2f%% MAIOR "ANSI_COLOR_RESET,percent);   
        printf("que o original\n");
    }  
}

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

void print_message(char *message)
{
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif
    printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET, message);
    printf(ANSI_COLOR_BOLD"Comandos:\n-c <caminho do arquivo> para comprimir\n-d <caminho do arquivo> para descomprimir\n-o <caminho do arquivo> após o -c ou -d, para escolher o local onde vai ser salvo o arquivo\n-h para informações\n"ANSI_COLOR_RESET);    
}

int file_exists(char filePath[])
{
    FILE *file;
    if (file = fopen(filePath, "r")){
        fclose(file);
        return 1;
    }
    return 0;
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
                                    if(file_exists(argv[2]))
                                    {
                                        if(file_exists(argv[4]))
                                        {
                                            print_message("O arquivo de saída já existe, tente alterar o nome do mesmo!\n");    
                                        }
                                        else
                                        {
                                            compress(argv[2], argv[4]);
                                            print_file_sizes(argv[2], argv[4]);
                                        }                                                            
                                    }
                                    else
                                    {
                                        print_message("O arquivo de entrada não foi encontrado!\n");
                                    }                                    
                                } 
                                else 
                                {
                                    print_message("O Caminho de saída do arquivo não foi informado!\n");                                    
                                }
                            } 
                            else 
                            {
                                print_message("Entrada inválida!\n");
                            }
                        } 
                        else 
                        {
                            print_message("Entrada inválida!\n");
                        }
                    } 
                    else 
                    {
                        char string[250], substring[10];
                        strcpy(string,  argv[2]);  
                        strcpy(substring,  ".huff");   
                        strcat(string, substring);
                        if(file_exists(argv[2]))
                        {
                            if(file_exists(string))
                            {
                                print_message("O arquivo de saída default já existe, tente informar um nome diferente com -o!\n");    
                            }
                            else
                            {
                                compress(argv[2], string);
                                print_file_sizes(argv[2], string);
                            }
                        }
                        else
                        {
                            print_message("O arquivo de entrada não foi encontrado!\n");
                        }                          
                    }
                } 
                else 
                {
                    print_message("O Caminho do arquivo não foi informado!\n");
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
                                    if(file_exists(argv[2]))
                                    {
                                        if(file_exists(argv[4]))
                                        {
                                            print_message("O arquivo de saída já existe, tente alterar o nome do mesmo!\n");    
                                        }
                                        else
                                        {                                                                                                                                
                                            decompress(argv[2], argv[4]);

                                            printf(ANSI_COLOR_GREEN" - Arquivo descomprimido com sucesso\n" ANSI_COLOR_RESET);   
                                            printf(" - Arquivo ");
                                            printf(ANSI_COLOR_BOLD"%s "ANSI_COLOR_RESET, argv[2]);
                                            printf("descomprimido para ");
                                            printf(ANSI_COLOR_BOLD"%s \n"ANSI_COLOR_RESET, argv[4]);  
                                        }  
                                    }
                                    else
                                    {
                                        print_message("O arquivo de entrada não foi encontrado!\n");
                                    }                             
                                } 
                                else 
                                {
                                    print_message("O Caminho do arquivo não foi informado!\n");
                                }
                            } 
                            else 
                            {
                                print_message("Entrada inválida!\n");
                            }
                        } 
                        else 
                        {
                            print_message("Entrada inválida!\n");
                        }
                    }
                    else 
                    {
                        char *string;
                        strcpy(string, argv[2]);
                        remove_substring(string, ".huff");
                        if(file_exists(argv[2]))
                        {
                            if(file_exists(string))
                            {
                                print_message("O arquivo de saída default já existe, tente informar um nome diferente com -o!\n");    
                            }
                            else
                            {                                                                                                                                
                                decompress(argv[2], string);

                                printf(ANSI_COLOR_GREEN" - Arquivo descomprimido com sucesso\n" ANSI_COLOR_RESET);   
                                printf(" - Arquivo ");
                                printf(ANSI_COLOR_BOLD"%s "ANSI_COLOR_RESET, argv[2]);
                                printf("descomprimido para ");
                                printf(ANSI_COLOR_BOLD"%s \n"ANSI_COLOR_RESET, string);  
                            }  
                        }
                        else
                        {
                            print_message("O arquivo de entrada não foi encontrado!\n");
                        } 
                    }
                } 
                else 
                {
                    print_message("O Caminho do arquivo não foi informado!\n");
                }
            } 
            else if(argv[1][1] == 'h')
            {
                print_message("Ajuda:\n");
            } 
            else 
            {
                print_message("Entrada inválida!\n");
            }
        } 
        else 
        {
            print_message("Entrada inválida!\n");
        }
    }
    else
    {
        print_message("Sem argumentos!\n");        
    }
    return;
}
