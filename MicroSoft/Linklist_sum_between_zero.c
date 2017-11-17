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

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

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

void print_list(struct node *hptr)
{
	while(hptr != NULL)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

void modify_with_sum(struct node *hptr)
{
int sum = 0;
struct node *temp = hptr;
struct node *cur = hptr;
struct node *pre = NULL;

	while(cur != NULL)
	{
		if(cur->num == 0)
		{
			temp->num = sum;
			sum = 0;
			pre = temp;
			temp = temp->next;
		}

		sum += cur->num;
		cur = cur->next;
	}

	if(temp->num != hptr->num)
	{
		pre->next = NULL;
	
		while(temp != NULL)
		{
			cur = temp;
			temp = temp->next;
			free(cur);
			cur = NULL;
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
