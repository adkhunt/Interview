#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

/////////////////////////////////////////////
//					   //
// Reverse the every k element in linklist //
//					   //
/////////////////////////////////////////////

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

struct node* reverse_linklist(struct node *hptr,int k)
{
int i = 0;
struct node *pre = null,*cur = hptr,*next = hptr;

	if(hptr == null)
		return pre;

	while(next && i < k)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		++i;
	}

	if(next != null)
		hptr->next = reverse_linklist(next,k);

	return pre;

}

int main()
{
struct node *hptr = null;
char ch;
int k;

	do{
		add_node_last(&hptr);
		printf("Do you want to continue?\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);

	printf("Enter group size to reverse the nodes.\n");
	scanf("%d",&k);

	hptr = reverse_linklist(hptr,k);

	print_list(hptr);

	return exit;
}
