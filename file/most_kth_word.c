#include<stdio.h>
#include<stdlib.h>
#include"new_trie.h"

/*
 * Program to find the most k tranding 
 * words in the file
 */

/*
 * Remove the special characters and convert
 * capital letters to small letters
 */

void remove_chars(char *str)
{
int i, index = 0;

	for(i = 0 ; str[i] ; ++i)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[index++] = str[i] + 32;

		else if(str[i] >= 'a' && str[i] <= 'z')
			str[index++] = str[i];
	}
}

/*
 * This function will read the file and insert into the
 * trie node and also build the heap array
 */

void get_k_word(char *file_name, int k)
{
FILE *fp = fopen(file_name, "r");

	if(fp == NULL)
	{
		printf("Error in opening file.\n");
		return;
	}

char word[20];
trie *root = NULL;
heap *arr = create_heap(k);

	while((fscanf(fp, "%s", word)) != EOF)
	{
		remove_chars(word);
		insert_word_trie(&root, arr, word, word);
	}

	print_heap(arr);
}

/*
 * Main function which start program
 */

int main()
{
char file_name[20];
int k_word;

	printf("Enter file name to read k word.\n");
	scanf("%s",file_name);

	printf("Enter K value.\n");
	scanf("%d",&k_word);

	get_k_word(file_name, k_word);

	return EXIT_SUCCESS;
}
