#include<stdio.h>
#include<stdlib.h>

/*
 * Program to adding two polynomial using
 * linklist
 */

/*
 * This structure variable holds the power
 * and base of the number
 */

struct node{
		int base;
		int power;	
		struct node *next;
};

/*
 * Returns the new node with number and 
 * power initialisation
 */

struct node* get_new_node(int num, int pow)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->base = num;
	temp->power = pow;
	temp->next = NULL;

	return temp;
}

/*
 * Print the list 
 */

void print_list(struct node *hptr)
{
	while(hptr)
	{
		printf("%d^%d",hptr->base, hptr->power);
		hptr = hptr->next;
		if(hptr)
			printf(" + ");
	}

	printf("\n");
}

/*
 * This function add two list with same power
 */

struct node* add_list(struct node *list1, struct node *list2)
{
	if(list1 == NULL)
		return list2;

	if(list2 == NULL)
		return list1;

struct node *res = NULL;

	if(list1->power == list2->power)
	{
		res = get_new_node(list1->base+list2->base, list1->power);
		list1 = list1->next;
		list2 = list2->next;
	}

	else if(list1->power > list2->power)
	{
		res = get_new_node(list1->base, list1->power);
		list1 = list1->next;
	}

	else
	{
		res = get_new_node(list2->base, list2->power);
		list2 = list2->next;
	}

struct node *temp = res;

	while(list1 && list2)
	{
		if(list1->power == list2->power)
		{
			temp->next = get_new_node(list1->base+list2->base, list1->power);
			list1 = list1->next;
			list2 = list2->next;
		}

		else if(list1->power > list2->power)
		{
			temp->next = get_new_node(list1->base, list1->power);
			list1 = list1->next;
		}

		else
		{
			temp->next = get_new_node(list2->base, list2->power);
			list2 = list2->next;
		}

		temp = temp->next;
	}

	while(list1)
	{
		temp->next = get_new_node(list1->base, list1->power);
		temp = temp->next;
		list1 = list1->next;
	}

	while(list2)
	{
		temp->next = get_new_node(list2->base, list2->power);
		temp = temp->next;
		list2 = list2->next;
	}

	return res;
}

int main()
{
struct node *hptr = NULL;
struct node *hptr2 = NULL;

	hptr = get_new_node(5, 2);
	hptr->next = get_new_node(4, 1);
	hptr->next->next = get_new_node(2, 0);

	hptr2 = get_new_node(5, 1);
	hptr2->next = get_new_node(5, 0);

	struct node *res = add_list(hptr, hptr2);

	print_list(hptr);
	print_list(hptr2);
	print_list(res);
	return EXIT_SUCCESS;
}
