#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/*
 * Program to serialise and deserialise a binary
 * search tree into file
 */

/*
 * This function will write the root data to the 
 * file in preorder manner if root is NULL than
 * it will write -1 so while deserialise we have
 * -1 as NULL indication
 */

void perform_serialise(struct node *root, FILE *fp)
{
	if(root == NULL)
	{
		fprintf(fp,"%d ",-1);
		return ;
	}

	fprintf(fp,"%d ",root->num);
	perform_serialise(root->left,fp);
	perform_serialise(root->right,fp);
}

/*
 * This function will open the file in write mode
 * and call the perform serialise function to
 * complete the serialisation
 */

void serialise(struct node *root,char * file_name)
{
	FILE *fp = fopen(file_name,"w");

	if(fp == NULL)
	{
		printf("Error in opening file.\n");
		return ;
	}

	perform_serialise(root,fp);
	fclose(fp);
}

/*
 * This function is to recover the data from file 
 * and constuct the binary search tree
 */

void perform_deserialise(struct node **root, FILE *fp)
{
int num;

	if(!fscanf(fp,"%d ",&num) || num == -1)
		return ;

	*root = get_new_node(num);
	
	perform_deserialise(&(*root)->left, fp);
	perform_deserialise(&(*root)->right, fp);
}

/*
 * This function will open the file in read mode
 * and call deserialise perform function
 */

void deserialise(struct node **root,char *file_name)
{
	FILE *fp = fopen(file_name,"r");

	if(fp == NULL)
	{
		printf("Error in opening file.\n");
		return ;
	}

	perform_deserialise(root, fp);
	fclose(fp);
}

int main()
{
struct node *root = NULL;
char ch;
	
	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printInorderIterative(root);

	serialise(root,"data.txt");

struct node *recover = NULL;

	deserialise(&recover,"data.txt");
	printInorderIterative(recover);
	printPreorderIterative(recover);

	return EXIT_SUCCESS;
}
