#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define exit 0

////////////////////////////////////////////////
//					      //
// To find the lowest common ancestor in tree //
//					      //
////////////////////////////////////////////////

struct node* find_ancestor(struct node *root,int num1,int num2)
{
	if(root == null)
		return root;

	if(root->num == num1 || root->num == num2)
		return root;

	struct node *lnode = find_ancestor(root->left,num1,num2);
	struct node *rnode = find_ancestor(root->right,num1,num2);

	if(lnode && rnode)
		return root;

	return lnode ? lnode : rnode;
}

int main()
{
struct node *root = getTree();
int num1,num2;

	printInorderIterative(root);

	printf("Enter two number to find lca.\n");
	scanf("%d%d",&num1,&num2);

	struct node *temp = find_ancestor(root,num1,num2);

	printf("Lowest Common Ancestor = %d\n",temp->num);

	return exit;
}
