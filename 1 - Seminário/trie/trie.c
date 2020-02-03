#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTER_SIZE 256

typedef struct Trie Trie;

struct Trie
{
	int isWord;
	struct Trie *character[CHARACTER_SIZE];
};

Trie *create_trie()
{
	int i;
	Trie *new_node = (Trie*) malloc(sizeof(Trie));
    
	new_node->isWord = 0;

	for(i = 0; i < CHARACTER_SIZE; i++)
    {
        new_node->character[i] = NULL;
    }

	return new_node;
}

void insert(Trie *root, char *string)
{
	int i;
	Trie *current = root;
    
	for(i = 0; i < strlen(string); i++)
	{
		if (current->character[string[i]] == NULL)
		{
            current->character[string[i]] = create_trie();
        }

		current = current->character[string[i]];
	}

	current->isWord = 1;
}

int search(Trie *root, char *string)
{
	if (root == NULL)
	{
        return 0;
    }

	int i;
	Trie *current = root;

	for(i = 0; i < strlen(string); i++)
	{
		current = current->character[string[i]];

		if (current == NULL)
		{
            return 0;
        }
	}

	return current->isWord;
}

int is_empty(Trie *current)
{
	int i;

	for(i = 0; i < CHARACTER_SIZE; i++)
    {
        if (current->character[i])
		{
            return 0;
        }
    }

	return 1;
}

Trie *delete(Trie *root, char *string, int depth)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(depth == strlen(string)){
		if(root->isWord == 1)
		{
			root->isWord = 0;
		}

		if(is_empty(root)){
			free(root);
			root = NULL;
		}

		return root;
	}

	root->character[string[depth]] = delete(root->character[string[depth]], string, depth + 1);

	if(is_empty(root) && root->isWord == 0){
		free(root);
		root = NULL;
	}

	return root;
}

void main(){
	Trie *root = create_trie();

	insert(root, "casa");
	printf("%s\n", search(root, "casa") ? "true" : "false");
    insert(root, "cada");
	printf("%s\n", search(root, "cada") ? "true" : "false");
	printf("%p\n", root);
	root = delete(root, "casa", 0);
	printf("%s\n", search(root, "casa") ? "true" : "false");
    printf("%s\n", search(root, "cada") ? "true" : "false");
	printf("%p\n", root);8
}