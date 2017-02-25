#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

//////////////////////////////////////////////////
//						//
// Program to get the maximum between two nodes //
// Entered by user				//
//						//
//////////////////////////////////////////////////

int max(int a,int b)
{
	return a > b ? a : b;
}

int max_in_subTree(struct node *root,int num)
{
int max_num = root->num;

	while(root->num != num)
	{
		max_num = max(root->num,max_num);

		if(root->num > num)
			root = root->left;

		else
			root = root->right;
	}

	return max_num;
}

struct node* get_lca(struct node *root,int num1,int num2)
{
	if(root == null)
		return root;

	if(root->num == num1 || root->num == num2)
		return root;

	struct node *left_lca = get_lca(root->left,num1,num2);
	struct node *right_lca = get_lca(root->right,num1,num2);

	if(left_lca && right_lca)
		return root;

	else
		return left_lca ? left_lca : right_lca;
}

int get_maximum(struct node *root,int num1,int num2)
{
	struct node *lca = get_lca(root,num1,num2);

	return max(max_in_subTree(lca,num1),max_in_subTree(lca,num2));
}

int main()
{
struct node *root = getTree();
int num1,num2;

	printf("Enter two number to find maximum number between them.\n");
	scanf("%d%d",&num1,&num2);

	int max_number = get_maximum(root,num1,num2);

	printf("Maximum between %d and %d is %d\n",num1,num2,max_number);

	return EXIT_SUCCESS;
}
