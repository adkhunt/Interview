#ifndef trie
#define trie

#include<stdlib.h>
#include<stdbool.h>
#define null NULL

typedef struct node{
			struct node *ptr[256];
			bool eow;
			int count;
} node;

node* get_new_node(void)
{
int i;

	node *temp = (node*) malloc(sizeof(node));
	
	for(i = 0 ; i < 256 ; ++i)
		temp->ptr[i] = null;

	temp->eow = false;
	temp->count = 0;

	return temp;
}

void insert_word(node **head,char *str)
{
int i;
node *temp = *head;

	for(i = 0 ; str[i] ; ++i)
	{
		if(temp->ptr[str[i]] == null)
			temp->ptr[str[i]] = get_new_node();

		temp = temp->ptr[str[i]];
	}

	temp->eow = true;
	++(temp->count);
}

void print_word( node *root )
{
int i; 

	for( i = 0; i < 256; i++)
	{
		if( root->ptr[i] != NULL){
			printf("%c", i);
			print_word(root->ptr[i]);
		}

	}
	
	if(root->eow == true)
		printf(" -> %d\n",root->count);
}

bool search_word(node *data,char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i)
	{
		if(data->ptr[str[i]] == null)
			return false;

		data = data->ptr[str[i]];
	}

	return true;
}

#endif
