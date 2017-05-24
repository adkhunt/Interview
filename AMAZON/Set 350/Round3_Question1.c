#include<stdio.h>
#include<stdlib.h>

/*
 * Program to adding two polynomial using
 * linklist
 */

struct node{
		int base;
		int power;	
		struct node *next;
};

struct node* get_new_node(int num, int pow)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->base = num;
	temp->power = pow;
	temp->next = NULL;

	return temp;
}

void add_node(struct node **hptr, int num, int pow)
{

}

int main()
{



	return EXIT_SUCCESS;
}
