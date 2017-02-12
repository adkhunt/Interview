#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

///////////////////////////////////////////////
//					     //
// Program to sort linklist using merge sort //
//					     //
///////////////////////////////////////////////

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

struct node* merge(struct node *first,struct node *second)
{
	if(first == null)
		return second;

	else if(second  == null)
		return first;

struct node  *res = null;

	if(first->num >= second->num)
	{
		res = second;
		res->next = merge(first,second->next);
	}

	else
	{
		res = first;
		res->next = merge(first->next,second);
	}

	return res;
}

void partition(struct node *hptr,struct node **first,struct node **second)
{
	if(hptr == null || hptr->next == null)
	{
		*first = hptr;
		*second = null;
	}

	else
	{
		struct node *slow = hptr;
		struct node *fast = hptr->next;

		while(fast)
		{
			fast = fast -> next;
			if(fast)
			{
				slow = slow -> next;
				fast = fast->next;
			}
		}

		*first = hptr;
		*second = slow->next;
		slow->next = null;
	}
}

void merge_sort(struct node **hptr)
{
	if(*hptr == null || (*hptr)->next == null)
		return ;

	struct node *first = null;
	struct node *second = null;

	partition(*hptr,&first,&second);
	merge_sort(&first);
	merge_sort(&second);

	*hptr = merge(first,second);
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		add_node_last(&hptr);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'Y' || ch == 'y');

	print_list(hptr);
	merge_sort(&hptr);
	print_list(hptr);

	return exit;
}
