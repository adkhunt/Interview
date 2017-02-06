#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

////////////////////////////////////////////////////
//						  //
// Program to check if given list is pelindrom or //
// Not in O(1) extra space			  //
//						  //
////////////////////////////////////////////////////

struct node{
		int num;
		struct node *next;
};

struct node* getNode(int num)
{
	struct node *ret = (struct node*)
				malloc(sizeof(struct node));

	ret->num = num;
	ret->next = null;

	return ret;
}

void addLast(struct node **hptr)
{
int num;
static struct node *pre = null;

	printf("Enter number in node.: ");
	scanf("%d",&num);

	if(*hptr)
	{
		pre->next = getNode(num);
		pre = pre->next;
	}

	else
	{
		*hptr = getNode(num);
		pre = *hptr;
	}
}

void printList(struct node *hptr)
{
	printf("\n");
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

struct node* checkPelindrom(struct node *start,struct node *last,int *flag)
{
	if(last == null)
		return start;

	struct node *nxt = checkPelindrom(start,last->next,flag);
	
	if(nxt->num != last->num)
		*flag = 0;

	return nxt->next;
}

int isPelindrom(struct node *hptr)
{
int i = 1;

	checkPelindrom(hptr,hptr,&i);

	return i;
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		addLast(&hptr);
		printf("Do you want to continue? (Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printList(hptr);
	if(isPelindrom(hptr))
		printf("Given list is pelindrom.\n");

	else
		printf("Given list is not pelindrom.\n");
	return exit;
}
