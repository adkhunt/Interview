#include<stdio.h>
#include<stdlib.h>

#define exit 0
#define null NULL

///////////////////////////////////////////////////
//						 //
// Program to delete a node from tail given by n //
// Without counting the nodes			 //
//						 //
///////////////////////////////////////////////////

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

	printf("Enter number in new node.\n");
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

void perform_delete(struct node *hptr,int n,int *count)
{
	if(hptr == null)
		return;

	perform_delete(hptr->next,n,count);

	if(*count == n)
	{
		struct node *temp = hptr->next;
		hptr->next = temp->next;
		free(temp);
	}

	++(*count);
}

void delete(struct node **hptr,int n)
{
int count = 0;
struct node *head = *hptr;

	perform_delete(head,n,&count);
}
int main()
{
struct node *hptr = null;
char ch;
int k;

	do{
		add_node_last(&hptr);
		printf("Do you want to continue.\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);
	printf("Enter k to print node from last.\n");
	scanf("%d",&k);

	delete(&hptr,k);
	print_list(hptr);

	return exit;
}
