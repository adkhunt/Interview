#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

//////////////////////////////////////////
//					//
// Get the nearest number from the tree //
//					//
//////////////////////////////////////////

int get_nearest(struct node *root,int num)
{
	if(root == null)
		return 0;

struct node *parent = null;
int diff = 65535,final_result = 65535;

	while(root)
	{
		if(root->num == num)
			return num;

		if(diff > abs(num-root->num))
		{
			diff = abs(num-root->num);
			final_result = root->num;
		}

		if(root->num > num)
			root = root->left;

		else
			root = root->right;
	}

	return final_result;
}

int main()
{
struct node *root = getTree();
int num;

	printf("\n=============================\n");
	printInorderIterative(root);
	printf("\n=============================\n");	

	printf("Enter number to get nearest number.\n");
	scanf("%d",&num);

	int nearest = get_nearest(root,num);

	printf("Nearest number to %d is %d\n",num,nearest);

	return EXIT_SUCCESS;
}
