#include<stdio.h>
#include<stdlib.h>

/*
 * Program to print the list in reverse order
 */

/*
 * List node variable which holds num field and
 * one next pointer
 */

struct node{
		int num;
		struct node *next;
};

/*
 * Return the new initialised node with passed 
 * parameters
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

/*
 * Adds the new node at the end of linklist
 */

void add_node(struct node **hptr, int num)
{
static struct node *pre = NULL;

	if(*hptr != NULL)
	{
		pre->next = get_new_node(num);
		pre = pre->next;
	}

	else
	{
		*hptr = get_new_node(num);
		pre = *hptr;
	}	
}

/*
 * Print the linklist in the normal order
 */

void print_list(struct node *hptr)
{
	while(hptr != NULL)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

/*
 * Print the linklist in the reverse order
 * using the recursion
 */

void print_reverse(struct node *hptr)
{
	if(hptr == NULL)
		return;

	print_reverse(hptr->next);
	printf("%d ",hptr->num);
}

int main()
{
struct node *hptr = NULL;
int i;

	for(i = 1 ; i < 10 ; ++i)
		add_node(&hptr, i);

	printf("=== In normal order ===\n");
	print_list(hptr);

	printf("=== In Reverse Order ===\n");
	print_reverse(hptr);
	printf("\n");

	return EXIT_SUCCESS;
}
