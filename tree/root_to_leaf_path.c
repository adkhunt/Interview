#include<stdio.h>
#include<stdlib.h>

/*
 * This header file contain basic operations 
 * which are like insert into tree delete from tree
 * print tree. 
 */

#include"tree.h"

/*
 * program to print the all path from root
 * to leaf
 */

int tree_height(struct node *root)
{

	/* 
	 * This function will return the height of the tree from
	 * root
	 */

	if(root == NULL)
		return 0;

	int lh = tree_height(root->left) + 1;
	int rh = tree_height(root->right) + 1;

	return rh > lh ? rh : lh;
}

void print(int *a,int limit)
{
int i;

	/* This function will print the 
	 * array upto limit which is passed 
	 * in parameter
	 */

	for(i = 0 ; i <= limit ; ++i)
		printf("%d ",a[i]);

	printf("\n");
}

void print_all_path(struct node *root,int *a,int level)
{
	if(root == NULL)
		return;

	/* This function will add the visited node
	 * into the array and when its leaf node
	 * we just print the array
	 */

	if(root->left == NULL && root->right == NULL)
	{
		a[level] = root->num;
		print(a,level);
	}

	a[level] = root->num;
	print_all_path(root->left,a,level+1);
	print_all_path(root->right,a,level+1);
}

void print_root_to_leaf(struct node *root)
{
int height = tree_height(root);
int *table = (int*) malloc(sizeof(int)*height); // Allocate the dynamic memory

	print_all_path(root,table,0);
}

int main()
{
struct node *root = NULL;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printInorderIterative(root);

	print_root_to_leaf(root);

	return EXIT_SUCCESS;
}
