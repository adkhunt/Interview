#include<stdio.h>
#include<stdlib.h>

/*
 * Given a linked list which contains series 
 * of numbers seperated by “0”. Add them and 
 * store in the linked list in-place.
 */

struct node{
		int num;
		struct node *next;
};

/*
 * This function return the new created node with
 * passed number and next pointer with null
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

/*
 * This function add the node at the end of the 
 * linklist
 */

void add_node_to_list(struct node **hptr, int num)
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
 * This function print the linklist 
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
 * This is the main function which makes the 
 * resultant linklist as the requirement 
 */

void modify_with_sum(struct node *hptr)
{
int sum = 0;
struct node *temp = hptr;
struct node *cur = hptr;
struct node *pre = NULL;

	while(cur != NULL)
	{
		if(cur->num != 0)
		{
			sum += cur->num;
			cur = cur->next;
		}

		else
		{
			temp->num = sum;
			temp->next = cur->next;
			free(cur);
			cur = NULL;
			cur = temp->next;
			temp = temp->next;
			sum = 0;
		}

	}
}

int main()
{
struct node *hptr = NULL;
char ch;
int num;

	do{
		printf("Enter number in new node.\n");
		scanf("%d",&num);
		add_node_to_list(&hptr, num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);
	
	modify_with_sum(hptr);
	print_list(hptr);

	return SUCCESS;
}
