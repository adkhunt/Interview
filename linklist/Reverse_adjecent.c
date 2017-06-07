#include<stdio.h>
#include<stdlib.h>

/*
 * Program to swap the adjecent nodes of the given 
 * linklist
 */

/*
 * This struct variable variable store the data and
 * next pointer to the linklist
 */

struct node{
		int num;
		struct node *next;
};

/*
 * This function return the new struct node with
 * initialisation of data with passed number and 
 * next pointer to the null
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
 * This function add the node at the end of
 * the struct variable
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
 * This function print the lisklist
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
 * This function swap the adjecent nodes of
 * the linklist using recursion
 */

struct node* Swap_adjecent(struct node *hptr)
{
	if(hptr == NULL || hptr->next == NULL)
		return hptr;

	struct node *temp = hptr->next;
	struct node *ret = temp->next;

	temp->next = hptr;
	hptr->next = Swap_adjecent(ret);	
	
	return temp;
}

int main()
{
struct node *hptr = NULL;
int i;

	for(i = 1 ; i < 10 ; ++i)
		add_node(&hptr, i);

	print_list(hptr);
	hptr = Swap_adjecent(hptr);
	print_list(hptr);

	return EXIT_SUCCESS;
}
