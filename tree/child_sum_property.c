#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define exit 0

/////////////////////////////////////////////////
//					       //
// Program to check weather root is sum of its //
// Child or not				       //
//					       //
/////////////////////////////////////////////////

bool is_valid_property(struct node *root)
{
	if(root == null || (root -> right == null && root->left == null))
		return true;

	int left_data,right_data;

	left_data = root->left ? root->left->num : 0;
	right_data = root->right ? root->right->num : 0;

	if((left_data+right_data) != root->num)
		return false;

	bool lr = is_valid_property(root->left);
	bool rr = is_valid_property(root->right);

	return lr && rr;
}

int main()
{
struct node *root = get_new_node(10);

	root->left = get_new_node(8);
	root->left->left = get_new_node(3);
	root->left->right = get_new_node(5);
	root->right = get_new_node(2);
	root->right->left = get_new_node(2);

	printInorderRecursive(root);
	printf("\n\n");

	if(is_valid_property(root))
		printf("Given tree is satisfy child sum property.\n");

	else
		printf("Tree Doesn't satisfy child sum property.\n");

	return exit;
}
