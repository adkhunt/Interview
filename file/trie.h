#ifndef trie
#define trie

#include<stdlib.h>
#include<stdbool.h>
#define null NULL

typedef struct node{
			struct node *ptr[230];
			bool eow;
			int count;
} node;

node* get_new_node(void)
{
int i;

	node *temp = (node*) malloc(sizeof(node));
	
	for(i = 0 ; i < 230 ; ++i)
		temp->ptr[i] = null;

	temp->eow = false;
	temp->count = 0;

	return temp;
}

void insert_word(node **head,char *str)
{
int i;
node *temp = *head;
int index;

	for(i = 0 ; str[i] ; ++i)
	{
		index = (str[i] >= 'A' && str[i] <= 'Z') ? str[i]+32 : str[i];

		if(temp->ptr[index] == null)
			temp->ptr[index] = get_new_node();

		temp = temp->ptr[index];
	}

	temp->eow = true;
	++(temp->count);
}

void print_word( node *root ,char *str,int level)
{
int i; 

	for( i = 0; i < 230 ; i++)
	{
		if( root->ptr[i] != NULL){
			str[level] = (char) i;
			print_word(root->ptr[i],str,level+1);
		}

	}
	
	if(root->eow == true)
	{
		str[level] = '\0';
		printf("%s -> %d\n",str,root->count);
	}
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
