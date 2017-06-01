#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LIST_SIZE 8
#define TOTAL_CHAR 26

/*
 * Program to print the anagram together from the 
 * list
 */

/*
 * This struct variable stores the index according to
 * character and one integer which stores the list
 * index and one bool variable which indicate if the
 * word is ended or not
 */

struct TRIE{
		struct TRIE *ptr[TOTAL_CHAR];
		int *arr;
		bool eow;
};

typedef struct TRIE Trie;

/*
 * This function return the new trie node with 
 * initiliase all pointer to null and end of word 
 * flag to false and if its last character of word
 * than it allocate int array memory to its leaf node
 */

Trie* get_trie_node(bool is_last_char,int size)
{
	Trie *node = (Trie*) malloc(sizeof(Trie));

int i;
	for(i = 0 ; i < TOTAL_CHAR ; ++i)
		node->ptr[i] = NULL;

	if(is_last_char == true)
	{
		node->arr = (int*) malloc(sizeof(int)*size);
		for(i = 0 ; i < size ; ++i)
			node->arr[i] = -1;
	}

	node->eow = false;

	return node;
}

/*
 * Return the index according to index
 */

int char_to_index(char ch)
{
	return (int) ch - 97;
}

/*
 * This function swap the two char variable
 * value
 */

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * This function add the string to the trie structure
 */

void add_word_to_trie(char *str, Trie *root, int list_ind)
{
int i;

	for(i = 0 ; str[i] ; ++i)
	{
		int index = char_to_index(str[i]);

		if(root->ptr[index] == NULL)
			root->ptr[index] = get_trie_node(str[i+1] == '\0',LIST_SIZE);

		root = root->ptr[index];
	}

	i = 0;
	while(root->arr[i] != -1)
		++i;

	root->arr[i] = list_ind;
	root->eow = true;
}

/*
 * This function sort the string using bubble sort
 */

void sort_word(char *str)
{
int i, j;

	for(i = 0 ; str[i+1] ; ++i)
	{
		for(j = 0 ; str[j+i+1] ; ++j)
		{
			if(str[j] > str[j+1])
				swap(str+j, str+j+1);
		}
	}
}

/*
 * Copy the string from source to the destination
 */

void my_strcpy(char *dest, const char *src)
{
int i;

	for(i = 0 ; src[i] ; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
}

/*
 * This function print the trie structure
 */

void print_trie(Trie *root, char **list)
{
	if(root == NULL)
		return ;

int i;

	for(i = 0 ; i < TOTAL_CHAR ; ++i)
	{
		if(root->ptr[i] != NULL)
			print_trie(root->ptr[i], list);
	}

	if(root->eow == true)
	{
		int j = 0;

		while(root->arr[j] != -1)
		{
			printf("%s ",list[root->arr[j]]);
			++j;
		}
	}
}

/*
 * This is the main function which called from the 
 * main function to print the anagram from the list
 * together
 */

void print_anagram_list(char **list)
{
int i,j;
char buff[20];
Trie *root = get_trie_node(false, LIST_SIZE);

	for(i = 0 ; i < LIST_SIZE ; ++i)
	{
		my_strcpy(buff, list[i]);
		sort_word(buff);
		add_word_to_trie(buff, root, i);
	}

	print_trie(root, list);
	printf("\n");
}

int main()
{
char* word_list[] = {"bats","cat","scare","potion","option","cares","act","tabs"};

	print_anagram_list(word_list);

	return EXIT_SUCCESS;
}
