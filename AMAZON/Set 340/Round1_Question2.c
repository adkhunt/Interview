#include<stdio.h>
#include<stdlib.h>

/*
 * Program to find the kth smallest number from
 * given binary tree in O(n) time complexity
 */

/*
 * Structure variable which store the data
 * left and right self referencial structure
 * and one extra field name left_count which
 * store the left element count which helps to
 * get smallest elelment in O(h) time
 */

struct node{
		int num;
		struct node *left;
		struct node *right;
};

/*
 * This function will return the new node with 
 * initialisation which passed to the parameter
 */

struct node* get_new_node(int data)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = data;
	temp->left = temp->right = NULL;

	return temp;
}

/*
 * This function add the node into to binary
 * search tree
 */

void add_node(struct node **root)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	if(*root)
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
 * Function to print the binary tree
 */

void print_tree(struct node *root)
{
	if(root == NULL)
		return ;

	print_tree(root->left);
	printf("%d ",root->num);
	print_tree(root->right);
}

/* 
 * This function will find the kth smallest
 * number from the binary search tree in
 * O(h) time
 */

void find_kth_smallest(struct node *root,int* k)
{
	if(root == NULL)
		return;

	
	find_kth_smallest(root->left,k);
	--(*k);
	if(*k == 0)
		printf("minimum = %d\n",root->num);
	find_kth_smallest(root->right,k);
}

int main()
{
struct node *root = NULL;
char ch;
int k;

	do{
		add_node(&root);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_tree(root);
	printf("\n");

	printf("Enter k value to get smallest.\n");
	scanf("%d",&k);

	find_kth_smallest(root,&k);

	return EXIT_SUCCESS;
}
