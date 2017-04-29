#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to find the longest leaf to leaf
 * path in binary tree.
 */

/*
 * Return the height of the binary tree
 */

int height(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left) + 1;
	int rh = height(root->right) + 1;

	return lh > rh ? lh : rh;
}

/*
 * Return the max of two numbers
 */

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
 * get the longest path in the binary tree
 */

int diameter(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	return max(lh+rh+1, max(ldiameter, rdiameter));
}

int main()
{
struct node *root = getTree();
char ch;

	printInorderIterative(root);

	int ltol = diameter(root);

	printf("Longest path = %d\n",ltol);

	return EXIT_SUCCESS;
}
