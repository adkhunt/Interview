#include<stdio.h>
#include<stdlib.h>

/*
 * declare a structure which holds integer
 * and two self referencial sttucture pointer
 * one is for next node and one is for random
 * pointer
 */

struct node{
		int num;
		struct node *next;
		struct node *random_ptr;
};

/*
 * return the new node with initialising the
 * number field with passed num as parameter
 * random poointer and next pointer is initialised 
 * with null and return to the caller function
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;
	temp->random_ptr = NULL;

	return temp;
}

/* This function will add the new node to the list
 * if the list alredy exist than it will add new node
 * at the end of the if the list is null than add the
 * new node at the start of the list
 */

void add_list(struct node **hptr,int num)
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
 * This function will print the list
 * and random pointer which current pointer 
 * is pointing to
 */

void print_list(struct node *hptr)
{
	while(hptr)
	{
		printf("Main = %d\tRandom = %d\n",hptr->num,hptr->random_ptr->num);
		hptr = hptr->next;
	}
}

/*
 * This function will make the copy of
 * link list which is passed as a parameter
 */

struct node* clone_linklist(struct node *hptr)
{
struct node *cur = hptr;
struct node *temp = NULL;

	/*
	 * Insert the copy of current node into its next pointer
	 * Ex. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
	 * Convert To : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4' ... 
	 */

	while(cur)
	{
		temp = get_new_node(cur->num);
		temp->next = cur->next;
		cur->next = temp;
		cur = temp->next;
	}

cur = hptr;
struct node *clone = cur->next;
temp = clone;

	/*
	 * Connect the radom pointer into the
	 * Clone linklist
	 */

	while(cur)
	{
		temp->random_ptr = cur->random_ptr->next;
		cur = temp->next;
		if(cur)
			temp = cur->next;
	}

temp = clone;
cur = hptr;

	/*
	 * Split the original linklist and clone
	 * linklist
	 */

	while(cur)
	{
		cur->next = temp->next;
		cur = cur->next;
		if(cur)
			temp->next = cur->next;
		temp = temp->next;
	}


	return clone;
}

int main()
{
struct node *hptr = NULL;
int i=0;
struct node *array[6] = {NULL};

	add_list(&hptr,1);
	add_list(&hptr,2);
	add_list(&hptr,3);
	add_list(&hptr,4);
	add_list(&hptr,5);
	add_list(&hptr,6);

struct node *temp = hptr;

	while(temp)
	{
		array[i++] = temp;
		temp = temp->next;
	}

	/*
	 * This part connect the random pointer into 
	 * The created linklist
	 */

	array[0]->random_ptr = array[4];
	array[1]->random_ptr = array[2];
	array[2]->random_ptr = array[5];
	array[3]->random_ptr = array[0];
	array[4]->random_ptr = array[1];
	array[5]->random_ptr = array[3];

	print_list(hptr);
	
	struct node *clone = clone_linklist(hptr);

	printf("===== Cloned link-list =====\n");
	print_list(clone);
	return EXIT_SUCCESS;
}
