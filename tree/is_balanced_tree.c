#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree.h"

/*
 * Program to check if given tree is balanaced 
 * binary tree or not
 */

/*
 * This function will traverse the tree in 
 * post order fashion which return the height
 * of left tree and height of right sub-tree
 * and get the difference if difference between
 * them is more than two than the flag will set
 * to false 
 */

int is_balance(struct node *root, bool *is_bal)
{
	if(root == NULL)
		return 0;

	int lh = is_balance(root->left , is_bal) + 1;
	int rh = is_balance(root->right, is_bal) + 1;

	if(lh - rh < -1 || lh - rh > 1)
		*is_bal = false;

	return lh > rh ? lh : rh;
}

int main()
{
struct node *root = getTree();
bool is_bal = true;

	int bal = is_balance(root, &is_bal);

	if(is_bal)
		printf("Given tree is balanced binary tree.\n");
	else
		printf("Givan tree is not balanced.\n");

	return EXIT_SUCCESS;
}
