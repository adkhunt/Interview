#include<stdio.h>
#include<stdlib.h>

/*
 * Program to swap the adjecent nodes of the
 * singly linked list
 */

/*
 * Structure that hold data of node and 
 * next pointer
 */

struct node{
		int num;
		struct node *next;
};

/*
 * Return the new node of linklist
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
 * Add the new node at the end of the
 * given linklist
 */

void add_node(struct node **hptr, int num)
{
static struct node *pre = NULL;

	if(*hptr)
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
 * Print the linklist
 */

void print_node(struct node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

/*
 * This function recursively swap the
 * adjecent nodes from the linklist
 */

struct node* swap_nodes(struct node *hptr)
{
	if(hptr == NULL || hptr->next == NULL)
		return hptr;

	struct node *new_head = hptr->next;
	struct node *temp = new_head->next;
	hptr->next->next = hptr;

	hptr->next = swap_nodes(temp);

	return new_head;
}

int main()
{
struct node *hptr = NULL;
int num;
char ch;

	do{
		printf("Enter number in node.\n");
		scanf("%d",&num);
		add_node(&hptr, num);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_node(hptr);
	hptr = swap_nodes(hptr);
	print_node(hptr);		

	return EXIT_SUCCESS;
}
