#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to convert the binary tree
 * to it's mirror tree
 */

/*
 * This function will convert the binary 
 * tree into it's mirror tree by traversing
 * post order and swap the left node and right
 * node
 */

void convert_mirror_tree(struct node *root)
{
	if(root == NULL)
		return ;

	convert_mirror_tree(root->left);
	convert_mirror_tree(root->right);

	struct node *temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);
	printLevelOrder(root);
	convert_mirror_tree(root);

	printf("\n====== Mirror Tree ======\n");
	printInorderIterative(root);

	printLevelOrder(root);

	return EXIT_SUCCESS;
}
