#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to find the height of the binary tree
 * where all the leaf nodes are connected as a
 * circuler doubly linklist
 */

/*
 * This function checks if the passes node in the 
 * parameter is the leaf node or not
 */

bool is_leaf_node(struct node *root)
{
	if(root == NULL || root->left != NULL || root->right != NULL)
		return false;

	return true;
}

/*
 * This function connects leaf nodes of the binary
 * tree in the form of circuler doubly linklist
 */

void connect_leaf_list(struct node *root)
{
static struct node *last_node = NULL;
static struct node *first_node = NULL;

	if(first_node != NULL)
	{
		last_node->right = root;
		root->left = last_node;
		root->right = first_node;
		last_node = root;
	}

	else
	{
		first_node = root;
		last_node = root;
	}
}

/*
 * This function checks if the nodes is leaf node
 * than there left and right pointers are filled
 * with the linklist forms
 */

void connect_leaf_circuler(struct node *root)
{
	if(root == NULL)
		return ;

	connect_leaf_circuler(root->left);
	connect_leaf_circuler(root->right);
	
	if(is_leaf_node(root))
		connect_leaf_list(root);
}

/*
 * This function return the height of the binary
 * tree where all the leaf nodes are conneted as
 * a circuler linklist form
 */

int get_c_height(struct node *root, struct node *pre)
{
	if(root == NULL || root->left == pre || root->right == pre)
		return 0;

	int lh = get_c_height(root->left, root) + 1;
	int rh = get_c_height(root->right, root) + 1;

	return lh > rh ? lh : rh;
}

int main()
{
struct node *root = getReadyTree();

	printInorderIterative(root);
	connect_leaf_circuler(root);
	int height = get_c_height(root, root);

	printf("Height of tree = %d\n",height);

	return EXIT_SUCCESS;
}
