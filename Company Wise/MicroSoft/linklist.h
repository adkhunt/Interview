#ifndef LINKLIST
#define LINKLIST

#include<stdlib.h>

/*
 * This header file the utility of linklist
 * functionality where all basic function are
 * there to insert node at the end in list
 * print the list like function.
 */

/*
 * This is the structure variable which contain
 * one integer and one self referencial structure
 */

struct node{
		int num;
		struct node *next;
};

/*
 * This function will return the new allocated
 * with the number initialisation and next pointer to
 * null
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
 * This function add the new node at the
 * end of the linklist
 */

void add_node(struct node **hptr)
{
static struct node *pre = NULL;
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	if(*hptr != NULL)
	{
		pre -> next = get_new_node(num);
		pre = pre->next;
	}

	else
	{
		*hptr = get_new_node(num);
		pre = *hptr;
	}
}

/*
 * This function will return the new created
 * linklist to its caller function
 */

struct node* get_list(void)
{
struct node *hptr = NULL;
char ch;

	do{
		add_node(&hptr);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	return hptr;
}

/*
 * Print the linklist which we are passing 
 * Through the parameter
 */

void print_list(struct node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

#endif
