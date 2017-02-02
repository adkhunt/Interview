#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"stack.h"
#include"queue.h"

/////////////////////////////////////////////////////
//						   //
// Program to find the common element in two Trees //
//						   //
/////////////////////////////////////////////////////

int countNodes(struct node *root,int *count)
{
	if(root == null)
		return;

	++(*count);

	countNodes(root->left,count);
	countNodes(root->right,count);
}

void fillQueueInorder(struct node *root,Stack *q,int size)
{
Stack *s = create_stack(size);

	while(1)
	{
		if(root)
		{
			push(s,root);
			root = root->left;
		}

		else
		{

			if(isEmpty(s))
				break;
	
			root = pop(s);
			push(q,root);
			root = root->right;
		}
	}
}

void find_Same_Number(struct node *root,struct node *root1)
{
int firstNodes = 0;
int secondNodes = 0;

	countNodes(root,&firstNodes);
	countNodes(root1,&secondNodes);

Stack *q = create_stack(firstNodes+2);
Stack *q1 = create_stack(secondNodes+2);

	fillQueueInorder(root,q,firstNodes);
	fillQueueInorder(root1,q1,secondNodes);

	root = pop(q);
	root1 = pop(q1);

	while((!isEmpty(q)) && (!isEmpty(q1)))
	{
		
		if(root->num > root1->num)
		{
			root = pop(q);
		}

		else if(root->num < root1->num)
		{
			root1 = pop(q1);
		}

		else{
			printf("%d ",root->num);
			root = pop(q);
			root1 = pop(q1);
		}
	}

	printf("\n");
}

int main()
{
struct node *root = getTree();
printf("Enter second tree data\n");
struct node *root1 = getTree();

	printInorderRecursive(root);
	printf("\n");
	printInorderRecursive(root1);
	printf("\n");
	printf("\n");

	find_Same_Number(root,root1);

	return 0;
}
