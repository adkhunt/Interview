#include<stdio.h>
#include<stdlib.h>

/*
 * Program to get the middle node from
 * the linklist in single traversal
 */

/*
 * basic structure variable which holds the
 * integer and next pointer
 */

struct node{
		int num;
		struct node *next;
};

typedef struct node list_t;

/*
 * Return the list_t variable pointer with
 * basic intialisation and next pointer to 
 * null
 */

list_t* get_new_node(int num)
{
	list_t *temp = (list_t*) malloc(sizeof(list_t));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

/*
 * Add list at the end of the list
 */

void add_list(list_t **hptr, int num)
{
static list_t *pre = NULL;

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
 * Print the link list 
 */

void print_list(list_t *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

/*
 * Get the middle node from single traversal 
 * one fast pointer and one slow pointer is 
 * used where fast pointer is goes two node 
 * forward and slow pointer move only one node
 * so when fast pointer reaches to end tha slow
 * pointer points to middle node
 */

list_t* get_middle_node(list_t *hptr)
{
list_t *middle = hptr;

	while(hptr != NULL)
	{
		hptr = hptr->next;
		if(hptr != NULL)
		{
			middle = middle->next;
			hptr = hptr->next;
		}
	}

	return middle;
}

int main()
{
list_t *hptr = NULL;
char ch;
int num;

	do{
		printf("Enter number in new node.\n");
		scanf("%d",&num);
		add_list(&hptr, num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);
	list_t *middle = get_middle_node(hptr);

	printf("Middle Node = %d\n",middle->num);

	return EXIT_SUCCESS;
}
