#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define null NULL
#define exit_success 0

///////////////////////////////////////////////////
//						 //
// Program to check linklist is pelindrom or not //
// In single traversal				 //
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

void add_list(struct node **hptr)
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

struct node* check_pelindrome(struct node *head,struct node *tail,int *flag)
{
	if(tail == null)
		return head;

	struct node *nxt = check_pelindrome(head,tail->next,flag);

	if(nxt->num != tail->num)
		*flag = 1;

	return nxt->next;
}

bool isPelindrome(struct node *head)
{
int i = 0;

	check_pelindrome(head,head,&i);

	return i == 0;
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		add_list(&hptr);
		printf("Do you want to continue(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);

	if(isPelindrome(hptr))
		printf("Linklist is pelindrome.\n");

	else
		printf("Linklist is not pelindrome.\n");

	return exit_success;
}
