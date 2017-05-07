#ifndef NEW_TRIE
#define NEW_TRIE

#include<stdbool.h>

/*
 * This header file is for store the word
 * in trie data structure and also used to
 * store the min heap for getting the most
 * kth trending word in file
 */

/*
 * This is the trie node which contain
 * with the word_count and min_index variable
 * which store the index in the min heap
 * to calculate the most k word
 */

typedef struct TRIE_NODE{
				int word_count;
				int min_index;
				bool eow;
				struct TRIE_NODE *ptr[26];
} trie;

/*
 * This structure variable holds the frequency 
 * of the word leaf node of the trie word and
 * string for which its holding the data
 */

typedef struct HEAP_NODE{
				int freq;
				char word[20];
				trie *root;
} heap_node;

/*
 * This function will make the array of heap_node
 * structure and also have limit to kth value
 */

typedef struct HEAP{
			int limit;
			int cur_index;
			heap_node *heap_array;
} heap;

/*
 * Create heap array of size which is passed in the parameter
 * initialise the limit with capacity and cur_index to
 * zero
 */

heap* create_heap(int capacity)
{
	heap *temp = (heap*) malloc(sizeof(heap));

	temp->limit = capacity;
	temp->cur_index = 0;
	temp->heap_array = (heap_node*) malloc(sizeof(heap_node)*capacity);

	return temp;
}

/*
 * This function will swap the heap nodes
 * in the heap array
 */

void swap_heap_node(heap_node *first_node, heap_node *second_node)
{
	heap_node temp = *first_node;
	*first_node = *second_node;
	*second_node = temp;
}

/*
 * This function will copy the source string
 * into the destination string
 */

void my_strcpy(char *src, char *dest)
{
int i;

	for(i = 0 ; src[i] ; ++i)
		dest[i] = src[i];

	dest[i] = '\0';
}

/*
 * This function will heapfy the array
 */

void heapify(heap *arr, int min_index)
{
	int left_child = (min_index*2) + 1;
	int right_child = (min_index*2) + 2;
	int parent = min_index;

	if(left_child < arr->cur_index &&
		arr->heap_array[left_child].freq < arr->heap_array[parent].freq)
		parent = left_child;

	if(right_child < arr->cur_index &&
		arr->heap_array[right_child].freq < arr->heap_array[parent].freq)
		parent = right_child;

	if(parent != min_index)
	{
		arr->heap_array[parent].root->min_index = min_index;
		arr->heap_array[min_index].root->min_index = parent;
		swap_heap_node(&arr->heap_array[parent], &arr->heap_array[min_index]);
		heapify(arr, parent);
	}
}

/*
 * This function will build the heap array
 * from last parent node to root
 */

void build_array(heap *arr)
{
int i = (arr->cur_index-1)/2;

	for(i ; i >= 0 ; --i)
		heapify(arr, i);
}

/*
 * This function will insert the word and
 * its frequency into the heap array
 */

/*
 * There are three cases in this funtion 
 *
 * 1) If word is not present in the heap array
 * 2) if heap is not full
 * 3) Frequency of word is more than root
 */

void insert_word_heap(heap *arr, trie *root, char *word_to_insert)
{

	if(root->min_index != -1)
	{
		++(arr->heap_array[root->min_index].freq);
		heapify(arr, root->min_index);
	}

	else if(arr->cur_index < arr->limit)
	{
		root->min_index = arr->cur_index;
		arr->heap_array[arr->cur_index].freq = root->word_count;
		arr->heap_array[arr->cur_index].root = root;
		my_strcpy(word_to_insert, arr->heap_array[arr->cur_index].word);
		++arr->cur_index;
		build_array(arr);
	}

	else if(root->word_count > arr->heap_array[0].freq)
	{
		arr->heap_array[0].root->min_index = -1;
		arr->heap_array[0].root = root;
		arr->heap_array[0].freq = root->word_count;
		my_strcpy(word_to_insert, arr->heap_array[0].word);
		root->min_index = 0;

		heapify(arr, 0);
		
	}
}

/*
 * Return the new trie node 
 */

trie* get_new_trie_node(void)
{
	trie *new_node = (trie*) malloc(sizeof(trie));
	new_node->word_count = 0;
	new_node->min_index = -1;
	new_node->eow = false;
int i;

	for(i = 0 ; i < 26 ; ++i)
		new_node->ptr[i] = NULL;

	return new_node;
}

/*
 * Convert the character to the index
 * e.g. a = 0, b = 1, c = 3 ...
 */

int char_to_int(char ch)
{
	return (int) ch - 97;
}

/*
 * Insert the word into the trie node and also 
 * in the heap array
 */

void insert_word_trie(trie **root, heap *arr, char *word, char *copy_word)
{
	if(*root == NULL)
		*root = get_new_trie_node();

trie *temp = *root;
int i;

	for(i = 0 ; word[i] ; ++i)
	{
		int index = char_to_int(word[i]);

		if(temp->ptr[index] == NULL)
			temp->ptr[index] = get_new_trie_node();

		temp = temp->ptr[index];
	}

	temp->eow = true;
	++(temp->word_count);

	insert_word_heap(arr, temp, copy_word);
}

/*
 * Print the heap array with final result
 */

void print_heap(heap *arr)
{
int i;

	for(i = 0 ; i < arr->cur_index ; ++i)
		printf("%s -> %d\n",arr->heap_array[i].word, arr->heap_array[i].freq);
}

#endif
