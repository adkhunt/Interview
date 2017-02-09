#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define exit 0

///////////////////////////////////////
//				     //
// Print left and right view of Tree //
//				     //
///////////////////////////////////////

void printLeft(struct node *root,int *max_level,int cur_level)
{
	if(root == null)
		return ;

	if(*max_level < cur_level)
	{
		printf("%d\n",root->num);
		*max_level = cur_level;
	}

	printLeft(root->left,max_level,cur_level+1);
	printLeft(root->right,max_level,cur_level+1);
}

void printRight(struct node *root,int *max_level,int cur_level)
{
	if(root == null)
		return;

	if(*max_level < cur_level)
	{
		printf("%d\n",root->num);
		*max_level = cur_level;
	}

	printRight(root->right,max_level,cur_level+1);
	printRight(root->left,max_level,cur_level+1);
}

void printRightView(struct node *root)
{
int cur = -1;

	printRight(root,&cur,0);
}

void printLeftView(struct node *root)
{
int cur = -1;

	printLeft(root,&cur,0);
	printf("\n");
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);

	printLeftView(root);
	printRightView(root);

	return exit;
}
