#include<stdio.h>
#include<stdlib.h>
#include"map.h"

/*
 * This program is to print tree in vertical
 * order in O(n) time complexity using map
 */


/*
 * Structure variable to store the the data 
 * and left and right pointer in tree
 */
 
struct node{
		int num;
		struct node *left;
		struct node *right;
};

/*
 * Return the new node with basic initialisation
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/*
 * Add new node in the tree
 */

void add_node(struct node **root)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	if(*root)
	{
		struct node *cur = *root;
		struct node *pre = *root;

		while(cur)
		{
			pre = cur;

			if(cur->num >= num)
				cur = cur->left;
			else
				cur = cur->right;
		}

		if(pre->num >= num)
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
 * Print tree in inorder traversal using
 * recursion
 */

void print_tree(struct node *root)
{
	if(root == NULL)
		return;

	print_tree(root->left);
	printf("%d ",root->num);
	print_tree(root->right);
}

/*
 * store the node and the vertical level into 
 * the tree to print the tree in O(n) time
 */

void perform_order(struct node *root,int i,map **tab)
{
	if(root == NULL)
		return;

	map_add(tab,i,root->num);

	perform_order(root->left,i-1,tab);
	perform_order(root->right,i+1,tab);
}

void print_vertical(struct node *root)
{
map *tab = create_map();
int i = 0;

	perform_order(root,i,&tab);

	print_map(tab);
}

int main()
{
struct node *root = NULL;
char ch;

	do{
		add_node(&root);
		printf("Do you want to continue(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_tree(root);
	printf("\n");

	print_vertical(root);
	printf("\n");

	return EXIT_SUCCESS;
}
