#include<stdio.h>
#include<stdlib.h>

/*
 * Program to perform delete operation in the binary
 * search tree
 */

/*
 * This is the common structure variable that holds
 * the data and left right pointer
 */

struct node{
		int data;
		struct node *right;
		struct node *left;
};

/*
 * Return the new node of the tree
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->data = num;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

/*
 * Add the new node to the tree
 */

void add_node(struct node **root, int num)
{
	if(*root != NULL)
	{
		struct node *cur = *root;
		struct node *pre = *root;

		while(cur != NULL)
		{
			pre = cur;

			if(cur->data < num)
				cur = cur -> right;
			else
				cur = cur -> left;
		}

		if(pre->data > num)
			pre->left = get_new_node(num);
		else
			pre->right = get_new_node(num);
	}

	else
	{
		*root = get_new_node(num);
	}
}

/*
 * Print tree inorder
 */

void print_tree(struct node *root)
{
	if(root == NULL)
		return ;

	print_tree(root->left);
	printf("%d ",root->data);
	print_tree(root->right);
}

/*
 * Return the inorder successor from the tree
 */

int get_min(struct node *root)
{
	while(root->left != NULL)
		root = root->left;

	return root->data;
}

/*
 * This function recursive search for node and 
 * when node is found it perform the delete
 */

struct node* delete_node(struct node *root, int num)
{
	if(root == NULL)
		return root;

	if(root->data > num)
		root->left = delete_node(root->left, num);

	else if(root->data < num)
		root->right = delete_node(root->right, num);

	else
	{
		if(root->left == NULL || root->right == NULL)
		{
			struct node *temp = root->left ? root->left : root->right;
			free(root);
			root = NULL;
			return temp;
		}

		else
		{
			int min = get_min(root->right);
			root->data = min;
			root->right =  delete_node(root->right, min);
		}
	}

	return root;
}

int main()
{
struct node *root = NULL;
int arr[] = {10, 7, 3, 1, 6, 4, 18, 15, 14, 22, 25, 28};
int i, num;

	for(i = 0 ; i < 12 ; ++i)
		add_node(&root, arr[i]);

	print_tree(root);
	printf("\n");

	printf("Enter number number to delete.\n");
	scanf("%d",&num);

	root = delete_node(root, num);

	print_tree(root);
	printf("\n");

	return EXIT_SUCCESS;
}
