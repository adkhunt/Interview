#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define exit 0

////////////////////////////////////////////////////
//						  //
// Program to convert the bst to double link-list //
//						  //
////////////////////////////////////////////////////

void convert(struct node *root,struct node **head,struct node **tail)
{
	if(root == null)
		return;

	convert(root->left,head,tail);

	if(*head)
	{
		(*tail)->right = root;
		root->left = *tail;
	}

	else
	{
		*head = root;
	}

	*tail = root;

	convert(root->right,head,tail);
}

void convert_to_dll(struct node **root)
{
struct node *head = null;
struct node *tail = null;

	convert(*root,&head,&tail);
	*root = head;
}

void print_dll(struct node *root)
{
	while(root)
	{
		printf("%d ",root->num);
		root = root->right;
	}

	printf("\n");
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);
	convert_to_dll(&root);

	printf("Convert double link-list.\n");
	print_dll(root);

	return exit;
}
