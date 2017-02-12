#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

struct node{
		int num;
		struct node *next;
};

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = null;

	return temp;
}

void add_node_last(struct node **hptr)
{
static struct node *pre = null;
int num;

	printf("Enter number in node.\n");
	scanf("%d",&num);

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

void print_list(struct node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

void partition(struct node *hptr,struct node **first,struct node **second)
{
	if(hptr == null)
		return;

	struct node *slow = 
}

struct node* merge_sort(struct node *hptr)
{
	if(hptr == null)
		return hptr;

	struct node *first = null;
	struct node *second = null;

	partition(hptr,&first,&second);
	merge_sort(first);
	merge_sort(secod);

	return merge(first,second);
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		add_list_last(&hptr);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'Y' || ch == 'y');

	print_list(hptr);
	hptr = merge_sort(hptr);
	print_list(hptr);

	return exit;
}
