#include<stdio.h>
#include<stdlib.h>

/*
 * Program to find the inorder successor of the
 * binary search tree
 */

/*
 * This struct variable holds the data and
 * two pointers
 */

struct node{
		int data;
		struct node *right;
		struct node *left;
};

/*
 * Return the new node of the binary search
 * tree
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
 * Add new node in the binary search tree
 */

void add_node(struct node **root, int num)
{

	if(*root != NULL)
	{
		struct node *pre = *root;
		struct node *cur = *root;

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
 * Print the tree in inorder traversal
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
 * Search the node with passed number
 */

struct node *search_root(struct node *root, int num)
{
	while(root != NULL && root->data != num)
	{
		if(root->data < num)
			root = root->right;

		else
			root = root->left;
	}

	return root;
}

/*
 * Get the minimum in the sub tree of given node
 */

int min_right(struct node *root)
{
	while(root->left != NULL)
		root = root->left;

	return root->data;
}

/*
 * This function return the inrder successor of the
 * binary search treee
 */

int get_inorder_successor(struct node *root, int num)
{
struct node *pre = root;

	struct node *cur_root = search_root(root, num);

	if(cur_root ==  NULL)
		return -1;

	if(cur_root->right != NULL)
		return min_right(cur_root->right);

	while(root != NULL && root->data != num)
	{
		if(root->data > num)
		{
			pre = root;
			root = root->left;
		}

		else
			root = root->right;
	}

	return pre->data;
}

int main()
{
struct node *root =  NULL;
int arr[] = {10, 7, 3, 1, 6, 4, 18, 15, 14, 25, 22, 28};
int i, size, num;

	size = sizeof(arr)/sizeof(arr[0]);

	for(i = 0 ; i < size ; ++i)
		add_node(&root, arr[i]);

	print_tree(root);
	printf("\n");

	printf("Enter number to get inorder successor.\n");
	scanf("%d",&num);

	int res = get_inorder_successor(root, num);

	printf("Result = %d\n",res);

	return EXIT_SUCCESS;
}
