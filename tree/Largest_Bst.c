#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
 * Program to find the largest bst in the
 * given binary tree
 */

/*
 * This struct varible store the data and two left
 * and right pointer
 */

struct node{
		int num;
		struct node *right;
		struct node *left;
};

/*
 * This struct variable is used to store the information 
 * about largest bst till now we got and what are the 
 * min and max of that bst
 */

struct PAIR{
		bool is_bst;
		int size,min,max;
		struct node *res;
};

typedef struct PAIR pair;

/*
 * This function return the new node to the caller
 * function with some initialisation to that node
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

/*
 * Check weather the node is leaf node or not
 * if yes than return true else return false
 */

bool is_leaf(struct node *root)
{
	if(root == NULL)
		return false;

	if(root->left == NULL && root->right == NULL)
		return true;

	return false;
}

/*
 * Return the maximum size in the pair of two
 * which passed in the paremeter
 */

int max(pair a, pair b)
{
	return a.size > b.size ? a.size : b.size;
}

/*
 * Return the pair with updated data with maximum
 * number of nodes which forms the BST in the binary
 * tree till traversal
 */

pair verified_data(struct node *root, pair left_pair, pair right_pair)
{
	if(left_pair.is_bst == true && right_pair.is_bst == true &&
		root->num > left_pair.max && root->num < right_pair.min)
	{
		pair new_pair = {true, left_pair.size+right_pair.size+1,
				 left_pair.min, right_pair.max, root};
		return new_pair;
	}

	else
	{
		struct node *res = left_pair.size > right_pair.size ? left_pair.res : right_pair.res;
		pair new_pair = {false, max(left_pair, right_pair), 0, 0, res};
		return new_pair;
	}
}

/*
 * This is the main function to get the maximum
 * to find the largest BST we use post order traversal
 * to get the data at the root
 */

pair get_bst(struct node *root)
{
	if(root == NULL)
	{
		pair res = {true, 0, 0, 0, NULL};
		return res;
	}

	if(is_leaf(root))
	{
		pair ret = {true, 1, root->num, root->num, root};
		return ret;
	}

	pair left_pair = get_bst(root->left);
	pair right_pair = get_bst(root->right);

	return verified_data(root, left_pair, right_pair);
}

/*
 * Return the size from the pair structure
 */

int get_largest_bst(struct node *root)
{
	if(root == NULL)
		return 0;


	pair res = get_bst(root);

	return res.size;
}

int main()
{
struct node *root = get_new_node(25);

	root->left = get_new_node(18);
	root->left->left = get_new_node(19);
	root->left->left->right = get_new_node(15);
	root->left->right = get_new_node(20);
	root->left->right->left = get_new_node(18);
	root->left->right->right = get_new_node(25);
	root->right = get_new_node(50);
	root->right->left = get_new_node(35);
	root->right->left->left = get_new_node(20);
	root->right->left->left->right = get_new_node(25);
	root->right->left->right = get_new_node(40);
	root->right->right = get_new_node(60);
	root->right->right->left = get_new_node(55);
	root->right->right->right = get_new_node(70); 

/* struct node *root = get_new_node(50);
root->left = get_new_node(30);
root->left->left = get_new_node(5);
root->left->right = get_new_node(20);
root->right = get_new_node(60);
root->right->left = get_new_node(45);
root->right->right = get_new_node(70);
root->right->right->left = get_new_node(65);
root->right->right->right = get_new_node(80); */

	int largest_bst = get_largest_bst(root);

	if(largest_bst > 0)
		printf("Largest size of BST = %d\n",largest_bst);

	else
		printf("No BST Found.\n");

	return EXIT_SUCCESS;
}
