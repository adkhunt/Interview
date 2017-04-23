#ifndef MAP
#define MAP

/*
 * This header file will work same as the
 * map in for two integers 
 */

#include<stdlib.h>

/*
 * contain the data and next node to the 
 * link
 */

typedef struct SUB_NODE{
			int data;
			struct SUB_NODE *next;
} sub_nde;

/*
 * This structure variable contain the
 * data for main linklist with index
 */

typedef struct MAP_DATA{
			int index;
			struct MAP_DATA *main_next;
			sub_node *sub_link;
} map;

sub_node* get_sub_node(int num)
{
	sub_node *temp = (sub_node*) malloc(sizeof(sub_node));

	temp->data = num;
	temp->next = NULL;

	return temp;
}

map* get_main_node(int index)
{
	map *temp = (map*) malloc(sizeof(map));

	temp->index = index;
	temp->main_next = NULL;
	temp->sub_link = NULL;

	return temp;
}

map* create_map(void)
{
	map *temp = (map*) malloc(sizeof(map));

	temp->index = 0;
	temp->main_next = NULL;
	temp->sub_link = NULL;

	return temp;
}

void add_last(sub_node **hptr,int data)
{
sub_node *temp = *hptr;

	if(*hptr)
	{
		while(temp->next)
			temp = temp->next;

		temp->next = get_sub_node(data);
	}

	else
	{
		*hptr = get_sub_node(data);
	}
}

void map_add(map **hptr,int index, int data)
{
map *temp = *hptr;
map *pre = *hptr;

	if(temp->index > index)
	{
		*hptr = get_main_node(index);
		(*hptr)->main_next = temp;
		
		add_last(&((*hptr)->sub_link),data);
	}

	else
	{
		while(1)
		{
			if(temp == NULL || temp->index > index)
			{
				pre->main_next = get_main_node(index);
				pre = pre->main_next;
				pre->main_next = temp;

				add_last(&(pre->sub_link), data);
				return;
			}
			
			if(temp->index == index)
			{
				add_last(&(temp->sub_link), data);
				return;
			}

			pre = temp;
			temp = temp->main_next;
		}
	}
}

void print_map(map *hptr)
{
sub_node *temp = NULL;

	while(hptr != NULL)
	{
		temp = hptr->sub_link;

		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}

		printf("\n");
		hptr = hptr->main_next;
	}
}

#endif
