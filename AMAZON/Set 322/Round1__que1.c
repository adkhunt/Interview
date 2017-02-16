#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define exit_success 0
#define INT_MIN -65535
#define INT_MAX 65535
#define null NULL

//////////////////////////////////////
//				    //
// Check weather tree is bst or not //
//				    //
//////////////////////////////////////

struct node{
		int num;
		struct node *left;
		struct node *right;
};

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->right = null;
	temp->left = null;

	return temp;
}

void add_node(struct node **root)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	if(*root)
	{
		struct node *pre = null;
		struct node *cur = *root;

		while(cur)
		{
			pre = cur;

			if(cur->num >= num)
				cur = cur->left;

			else
				cur = cur->right;
		}

		if(pre->num >= num)
			pre->left = get_new_node(num);

		else
			pre->right = get_new_node(num);
	}

	else
	{
		*root = get_new_node(num);
	}
}

void print_tree(struct node *root)
{

	if(root == null)
		return;

	print_tree(root->left);
	printf("%d ",root->num);
	print_tree(root->right);
}

bool isBST(struct node *root,int min,int max)
{
	if(root == null)
		return true;


	if(root->num > max || root->num < min)
		return false;

	bool left_check = isBST(root->left,min,root->num);
	bool right_check = isBST(root->right,root->num,max);

	return left_check && right_check;		
}

int main()
{
struct node *root = null;
char ch;

	/*do{
		add_node(&root);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');*/

	root = get_new_node(10);
	root->left = get_new_node(7);
	root->right = get_new_node(12);
	root->left->right = get_new_node(8);
	root->left->right->left = get_new_node(5);	

	print_tree(root);
	printf("\n");	

	if(isBST(root,INT_MIN,INT_MAX))
		printf("Tree is Binary Search Tree.\n");

	else
		printf("Tree is not Binary Search Tree.\n");

	return exit_success;
}
