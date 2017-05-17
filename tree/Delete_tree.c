#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to delete full binary tree
 */

/*
 * This function delete the full tree 
 * to delete tree we traverse post order
 * traversal and we delete the root recursively
 */

void delete_tree(struct node *root)
{
	if(root == NULL)
		return;

	delete_tree(root->left);
	delete_tree(root->right);

	free(root);
	root = NULL;
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);
	delete_tree(root);

	printf("After Delete Tree.\n");
	printInorderIterative(root);

	return EXIT_SUCCESS;
}
