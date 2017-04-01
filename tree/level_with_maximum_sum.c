#include<stdio.h>
#include<stdlib.h>

/*
 * this header file is contain with
 * basic operation on the tree
 */
#include"tree.h"

struct pair_level{
			int sum,level;
};
/*
 * Program to find the level in binary tree
 * which has the maximum sum in level
 * To solve this question we travel through all 
 * nodes in the tree and we keep track of all level in 
 * auxilary integer array which stores the sum till now
 */

/* 
 * Below function will return the 
 * Height of the binary tree
 */

int height(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left) + 1;
	int rh = height(root->right) + 1;

	return lh > rh ? lh : rh;
}

/*
 * Below function will fill the all 
 * array index traverse in pre-order 
 * manner and store all the visited level
 */

void fill_array(struct node *root,int *a,int level)
{
	/*
	 * If root is null base case
	 * we just return from here
	 */

	if(root == NULL)
		return;

	/*
	 * Level Variable will track the record 
	 * of current level
	 */

	a[level] += root->num; // store the result in array

	/*
	 * Recursively call the right and left
	 * sub-tree
	 */

	fill_array(root->left,a,level+1);
	fill_array(root->right,a,level+1);
}

/*
 * Below function will return max of the pair of level 
 * and the sum which that level contain
 */

struct pair_level get_max_level(struct node *root)
{

	int hght = height(root);

int *table = (int *) malloc(sizeof(int)*hght);
int i; //Iterator which iterate through array

	for(i = 0 ; i < hght ; ++i)
		table[i] = 0;		// Initialise all index with the zero

	fill_array(root,table,0);

	static struct pair_level pair = {0,0}; // Initialise the pair with zero

	pair.sum = table[0];
	pair.level = 0;

	/*
	 * find the maximum in the array 
	 * and store the index and max sum
	 * into the pair struct variable
	 */

	for(i = 1 ; i < hght ; ++i)
	{
		if(pair.sum < table[i])
		{
			pair.sum = table[i];
			pair.level = i;
		}
	}

	free(table);
	return pair;
}

int main()
{
struct node *root = NULL;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'Y' || ch == 'y');

	printInorderIterative(root);	// Print the tree inorder manner

	struct pair_level res = get_max_level(root);

	printf("Level =  %d\tSum = %d\n",res.level,res.sum);

	return EXIT_SUCCESS;
}
