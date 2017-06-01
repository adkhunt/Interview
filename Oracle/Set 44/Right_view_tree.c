#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 12

/*
 * Program to print the right view of binary tree
 */

/*
 * This structure variable stores the number and
 * two pointer
 */

struct node{
		int num;
		struct node *right;
		struct node *left;
};

/*
 * This function return the new node of
 * struct node variable
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

/*
 * Adds the new node to the binary tree
 */

void add_node_tree(struct node **root, int num)
{
	if(*root != NULL)
	{
		struct node *cur = *root;
		struct node *pre = cur;

		while(cur != NULL)
		{
			pre = cur;

			if(cur->num > num)
				cur = cur->left;
			else
				cur = cur->right;
		}

		if(pre->num > num)
			pre->left = get_new_node(num);

		else
			pre->right = get_new_node(num);
	}

	else
	{
		*root = get_new_node(num);
	}
}

/*
 * This function prints the right view of 
 * binary tree
 */

void print_right_view(struct node *root, int *cur_level, int last_level)
{
	if(root == NULL)
		return ;

	if((*cur_level) < last_level)
	{
		printf("%d ",root->num);
		*cur_level = last_level;
	}

	print_right_view(root->right, cur_level, last_level+1);
	print_right_view(root->left, cur_level, last_level+1);
}

int main()
{
int arr[] = {10, 7, 3, 1, 6, 4, 18, 15, 14, 25, 22, 28};
struct node *root = NULL;
int i = 0;

	for(i = 0 ; i < ARRAY_SIZE ; ++i)
	{
		add_node_tree(&root, arr[i]);
	}

int cur_level = 0;

	print_right_view(root, &cur_level, 1);

	printf("\n");

	return EXIT_SUCCESS;
}
