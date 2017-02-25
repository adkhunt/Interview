#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

//////////////////////////////////////////////////
//						//
// Program to get the sum of k smallest element //
//						//
//////////////////////////////////////////////////

void calculate_sum(struct node *root,int k,int *sum,int *count)
{
	if(root == null || *count == k)
		return;

	calculate_sum(root->left,k,sum,count);
	if(k != *count)
	{
		++(*count);
		*sum += root->num;
	}

	calculate_sum(root->right,k,sum,count);
}

int getSum(struct node *root,int k)
{
int sum = 0,count = 0;

	calculate_sum(root,k,&sum,&count);

	return sum;
}

int main()
{
struct node *root = getTree();
int k;

	printInorderIterative(root);
	
	printf("Enter k to find the sum.\n");
	scanf("%d",&k);

	int sum = getSum(root,k);

	printf("Total sum = %d\n",sum);

	return EXIT_SUCCESS;
}
