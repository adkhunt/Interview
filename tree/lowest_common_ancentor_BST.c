#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to find the lowest common ancentor
 * in the Binary Search Tree in O(h) time
 */

/*
 * This function will return the lowest 
 * common ancentor of two numbers
 */

struct node* lowest_common_ancentor(struct node *root, int num1, int num2)
{
	if(root == NULL)
		return root;

	printf("Root = %d\n",root->num);

	if(root->num > num1 && root->num > num2)
		return lowest_common_ancentor(root->left, num1, num2);

	else if(root->num < num1 && root->num < num2)
		return lowest_common_ancentor(root->right, num1, num2);

	return root;
}

int main()
{
struct node *root = getTree();
int num1, num2;

	printf("Enter number to get lowest common ancentor.\n");
	scanf("%d%d",&num1,&num2);

	printInorderIterative(root);

	struct node *LCA = lowest_common_ancentor(root, num1, num2);

	if(LCA)
		printf("Lowest Common Ancentor = %d\n",LCA->num);

	else
		printf("No LCA Found.\n");

	return EXIT_SUCCESS;
}
