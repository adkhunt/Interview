#include<stdio.h>
#include<stdlib.h>

/* 
 * Program to get the length of the linklist using 
 * recursion
 */

/*
 * This struct variable holds the data and the next 
 * pointer to the next node
 */

struct node{
		int num;
		struct node *next;
};

/*
 * This function return the newly created node to
 * the caller function
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

/*
 * This function add the node in the linklist at the end
 */

void add_node(struct node **hptr, int num)
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
 * Function to print the linklist from the first to the
 * last
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
 * This function return the length of the linklist
 * using the recursion
 */

int get_length_list(struct node *hptr)
{
	if(hptr == NULL)
		return 0;

	return get_length_list(hptr->next) + 1;
}

int main()
{
struct node *hptr = NULL;
char ch;
int num;

	do{
		printf("Enter number to add node.\n");
		scanf("%d",&num);
		add_node(&hptr, num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	} while(ch == 'y' || ch == 'Y');

	print_list(hptr);

	int res = get_length_list(hptr);

	printf("Length = %d\n",res);

	return EXIT_SUCCESS;
}
