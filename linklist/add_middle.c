#include<stdio.h>
#include<stdlib.h>

typedef struct node{
		int num;
		struct node *next;
} node;

node* get_new_node(int num)
{
	node *new_node = (node*) malloc(sizeof(node));

	new_node->num = num;
	new_node->next = NULL;

	return new_node;
}

void add_middle(node **hptr, int num)
{
	if((*hptr) == NULL || (*hptr)->num > num)
	{
		
	}
}


int main()
{


	return 0;
}
