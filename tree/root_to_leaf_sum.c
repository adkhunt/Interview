#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree.h"

/*
 * Program to to get if given sum is
 * present in the root to leaf path in 
 * binary tree
 */

/*
 * Return true if the sum with given number is
 * present from root to leaf in the tree
 */

bool find_sum_path(struct node *root, int sum, int sum_till_now)
{
	if(root == NULL)
		return false;

	sum_till_now += root->num;

	if(root->left == NULL && root->right == NULL)
		return sum_till_now == sum ? true : false;

	bool lr = find_sum_path(root->left, sum, sum_till_now);
	bool rr = find_sum_path(root->right, sum, sum_till_now);

	return lr || rr;
}

bool has_sum(struct node *root, int sum)
{
	if(root == NULL)
		return false;

	return find_sum_path(root, sum, 0);
}

int main()
{
struct node *root = getTree();
int sum;

	printf("\n================================\n");
	printInorderIterative(root);
	printf("\n================================\n");

	printf("Enter sum to get path.\n");
	scanf("%d",&sum);

	if(has_sum(root,sum))
		printf("Contain root to leaf path with sum.\n");
	else
		printf("Not contain any path with such sum.\n");

	return EXIT_SUCCESS;
}
