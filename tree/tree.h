#ifndef tree
#define tree

#include"queue.h"
#include"stack.h"

#define null NULL

/*
 * This is the header file which perform 
 * all basic operation like insert node in
 * tree,print tree
 */

/*
 * This structure variable holds the integer
 * and two self referencial pointer 
 */

struct node{
		int num;
		struct node *right,*left;
};

/*
 * This function will return the new node with
 * some basic intialisation
 */

struct node* get_new_node(int num)
{
	struct node *ret = (struct node*) malloc(sizeof(struct node));

	ret->num = num;
	ret->right = ret->left = NULL;

	return ret;
}

/*
 * This function will insert the node in the 
 * tree
 */

void BuildTree(struct node **root,int num)
{

	struct node *new_node = get_new_node(num);

	if(*root)
	{
		struct node *cur = *root;
		struct node *pre = cur;

		while(cur)
		{
			pre = cur;

			if(cur->num >= num)
				cur = cur->left;

			else
				cur = cur->right;
		}

		if(pre->num >= num)
			pre->left = new_node;

		else
			pre->right = new_node;
	}

	else{

		*root = new_node;
	}
}

void insertInTree(struct node **root)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	BuildTree(root,num);
}

struct node* getTree()
{
struct node *root = null;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	return root;
}

struct node* getReadyTree(void)
{
struct node *root = null;
int arr[12] = {10,7,3,1,6,4,18,15,14,25,22,28},i;

	for(i = 0 ; i < 12 ; ++i)
		BuildTree(&root,arr[i]);

	return root;
}

/*
 * This function will print the tree in 
 * inorder fashion using resursion
 */

void printInorderRecursive(struct node *root)
{
	if(root)
	{
		printInorderRecursive(root->left);
		printf("%d ",root->num);
		printInorderRecursive(root->right);
	}
}

/*
 * This function will print the tree in
 * postorder fashion using resursion
 */

void printPostorderRecursive(struct node *root)
{
	if(root)
	{
		printPostorderRecursive(root->left);
		printPostorderRecursive(root->right);
		printf("%d ",root->num);
	}
}

/*
 * This function will print the tree in 
 * preorder fashion using recursion
 */

void printPreorderRecursive(struct node *root)
{
	if(root)
	{
		printf("%d ",root->num);
		printPreorderRecursive(root->left);
		printPreorderRecursive(root->right);
	}
}

/*
 * This function print the tree in inorder
 * fashion using morris traversal
 */

void printInorderIterative(struct node *root) // Morris Traversaal
{
	if(root == NULL)
		return;		//Base Case

	while(root != NULL)
	{
		if(root->left == NULL)
		{
			printf("%d ",root->num);
			root = root->right;
		}

		else{
			struct node *pre = root->left;

			while(pre->right != NULL && pre->right != root)
				pre = pre->right;

			if(pre->right ==  NULL)
			{
				pre->right = root;
				root = root->left;
			}

			else if(pre->right == root)
			{
				pre->right = NULL;
				printf("%d ",root->num);
				root = root->right;
			}
		}
	}

	printf("\n");
}

/*
 * This function will print the tree in 
 * inorder fashion using stack 
 */

void printInorderStack(struct node *root)
{
Stack *s = create_stack(15);

	while(1)
	{
		if(root)
		{
			push(s,root);
			root = root->left;
		}

		else
		{
			if(isEmpty(s))
				break;

			root = pop(s);
			printf("%d ",root->num);
			root = root->right;
		}
	}

	printf("\n");
}

/*
 * This function will print the tree in 
 * preorder fashion using stack
 */

void printPreorderIterative(struct node *root)
{
	if(root == NULL)
		return;

Stack *s = create_stack(20);		//assume that tree element size is les than 20 // if size is more than 20 replace 20 ..

	push(s,root);

	while(!isEmpty(s))
	{
		root = pop(s);
		printf("%d ",root->num);
		
		if(root->right)
			push(s,root->right);

		if(root->left)
			push(s,root->left);
	}

	printf("\n");
}

/*
 * Print the tree in postorder traversal
 * using stack 
 */

void printPostorderIterative(struct node *root)
{

	if(root == NULL)
		return;

Stack *s = create_stack(20);
Stack *storeTraversal = create_stack(20);

	push(s,root);

	while(!isEmpty(s))
	{
		root = pop(s);
		push(storeTraversal,root);

		if(root->left)
			push(s,root->left);

		if(root->right)
			push(s,root->right);
	}

	while(!isEmpty(storeTraversal))
	{
		root = pop(storeTraversal);

		printf("%d ",root->num);
	}

	printf("\n");
}

/*
 * This function return the height 
 * of the tree
 */

int get_height(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = get_height(root->left) + 1;
	int rh = get_height(root->right) + 1;

	return lh > rh ? lh : rh;
}

/*
 * This function print the current level
 * using recursion
 */

void print_level(struct node *root, int cur_level, int level)
{
	if(root == NULL)
		return ;

	if(cur_level == level)
		printf("%d ",root->num);

	print_level(root->left, cur_level + 1, level);
	print_level(root->right, cur_level + 1, level);
}

/*
 * Print the all level of binary tree
 */

void printLevelOrder(struct node *root)
{
	if(root == NULL)
		return ;

int height = get_height(root), i;

	for(i = 1 ; i <= height ; ++i)
	{
		print_level(root, 1, i);
		printf("\n");
	}
}

#endif
