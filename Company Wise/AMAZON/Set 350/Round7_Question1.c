#include<stdio.h>
#include<stdlib.h>

/*
 * Remove all nodes which don’t lie in any path 
 * with sum>= k
 */

/*
 * Given a binary tree, a complete path is defined 
 * as a path from root to a leaf. The sum of all nodes 
 * on that path is defined as the sum of that path. 
 * Given a number K, you have to remove (prune the tree) 
 * all nodes which don’t lie in any path with sum>=k.
 */

/*
 * This strucutre variable holds the data variable
 * and two self referential structure
 */

struct node{
		int data;
		struct node *left;
		struct node *right;
};

/*
 * This function return the new node with 
 * data part initialised and pointer to NULL
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/*
 * This function add the node into the tree
 */

void add_node(struct node **root, int num)
{
struct node *pre = NULL;
struct node *cur = *root;

	if(*root != NULL)
	{
		while(cur)
		{
			pre = cur;

			if(cur->data > num)
				cur = cur->left;

			else
				cur = cur->right;
		}

		if(pre->data > num)
			pre->left = get_new_node(num);
		else
			pre->right = get_new_node(num);
	}

	else
		*root = get_new_node(num);
}

/*
 * This function remove the node which path
 * have sum less than passed parameter
 */

void remove_less_sum(struct node *root, struct node *pre, int sum, int cur_sum)
{
	if(root == NULL)
		return ;

	remove_less_sum(root->left, root, sum, cur_sum+root->data);
	remove_less_sum(root->right, root, sum, cur_sum+root->data);

	if((cur_sum+root->data) < sum && root->left == NULL && root->right == NULL)
	{
		if(pre -> left == root)
			pre->left = NULL;

		else if(pre->right == root)
			pre->right = NULL;

		free(root);
		root = NULL;
	}
}

/*
 * This function print the tree inorder traversal
 */

void print_tree(struct node *root)
{
	if(root == NULL)
		return ;

	print_tree(root->left);
	printf("%d ",root->data);
	print_tree(root->right);
}

int main()
{
struct node *root = NULL;
int sum;

	root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);
	root->left->left = get_new_node(4);
	root->left->right = get_new_node(5);
	root->right->left = get_new_node(6);
	root->right->right = get_new_node(7);
	root->left->left->left = get_new_node(8);
	root->left->left->right = get_new_node(9);
	root->left->right->left = get_new_node(12);
	root->right->right->left = get_new_node(10);
	root->right->right->left->right = get_new_node(11);
	root->left->left->right->left = get_new_node(13);
	root->left->left->right->right = get_new_node(14);
	root->left->left->right->right->left = get_new_node(15);

	print_tree(root);
	printf("\n");
	printf("Enter total number to get tree.\n");
	scanf("%d",&sum);

	remove_less_sum(root, root, sum, root->data);

	print_tree(root);
	printf("\n");

	return EXIT_SUCCESS;
}
