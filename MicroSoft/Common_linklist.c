#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#include"stack.h"

/*
 * Program to find the common node in the two
 * linklist in O(n+m) time complexity using stack
 */

/*
 * This function will join the common linklist at
 * end of the both main list so we can find the common 
 * list
 */

void join_two_list(struct node *list1,struct node *list2,struct node *common_list)
{

	while(list1->next != NULL)
		list1 = list1->next;

	while(list2->next != NULL)
		list2 = list2->next;

	list1->next = common_list;
	list2->next = common_list;
}

/*
 * This function will get the common node where 
 * two linklist are intersacting
 */

struct node* get_common_node(struct node *list1,struct node *list2)
{
stack *s1 = create_stack(20);
stack *s2 = create_stack(20);

	while(list1 != NULL)
	{
		push(s1,list1);
		list1 = list1->next;
	}

	while(list2 != NULL)
	{
		push(s2,list2);
		list2 = list2->next;
	}

list1 = (struct node*) pop(s1);
list2 = (struct node*) pop(s2);
struct node *temp = NULL;

	while(list1 == list2)
	{
		temp = list1;

		list1 = (struct node*) pop(s1);
		list2 = (struct node*) pop(s2);
	}

	return temp;
}

int main()
{
struct node *list1 = NULL, *list2 = NULL, *common_list = NULL;

	list1 = get_list();
	list2 = get_list();
	common_list = get_list();;

	join_two_list(list1,list2,common_list);

	print_list(list1);
	print_list(list2);

	struct node *common_node = get_common_node(list1,list2);

	if(common_node != NULL)
		printf("Common Node - %d\n",common_node->num);

	else
		printf("Linklist are not intersacting.\n");

	return EXIT_SUCCESS;
}
