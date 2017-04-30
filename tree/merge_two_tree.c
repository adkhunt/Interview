#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

/*
 * Program to merge two balanced binary
 * search tree into one balanced binary 
 * search tree
 */

/*
 * This function will convert the binary
 * search tree into the doubly link list
 */

void convert_tree_dll(avl_node *root, avl_node **head, avl_node **tail)
{
	if(root == NULL)
		return;

	convert_tree_dll(root->left, head, tail);

	if(*head == NULL)
		*head = root;

	else
	{
		(*tail)->right = root;
		root->left = *tail;
	}

	*tail = root;

	convert_tree_dll(root->right, head, tail);
}

/*
 * This function will merge the two sorted
 * doubly link list into one linklist
 */

avl_node* merge_two_list(avl_node *root1, avl_node *root2)
{
	if(root1 == NULL)
		return root2;

	if(root2 == NULL)
		return root1;

	if (root1->num < root2->num)
	{
		root1->right = merge_two_list(root1->right,root2);
		root1->right->left = root1;
		root1->left = NULL;
		return root1;
	}
	else
	{
		root2->right = merge_two_list(root1,root2->right);
		root2->right->left = root2;
		root2->left = NULL;
		return root2;
	}
}

/*
 * This function will return the total nodes
 * in the doubly linklist
 */

int count_node(avl_node *head)
{
int count = 0;

	while(head != 0)
	{
		head = head->right;
		++count;
	}

	return count;
}

/*
 * This function will convert the doubly linklist
 * into the binary search tree
 */

avl_node* convert_dll_tree(avl_node **head, int n)
{
	if(n <= 0)
		return NULL;

	avl_node *left_tree = convert_dll_tree(head, n/2);

	avl_node *root = *head;
	root->left = left_tree;
	*head = (*head)->right;

	root->right = convert_dll_tree(head, n-n/2-1);

	return root;
}

/*
 * Main function which will merge the two 
 * binary search tree into one
 */

avl_node* merge_tree(avl_node *root1, avl_node *root2)
{
avl_node *head1 = NULL, *head2 = NULL;
avl_node *tail1 = NULL, *tail2 = NULL;

	convert_tree_dll(root1, &head1, &tail1);
	convert_tree_dll(root2, &head2, &tail2);

	head1 = merge_two_list(head1, head2);

	int node_count = count_node(head1);

	return convert_dll_tree(&head1, node_count);
}

avl_node* get_avl_tree(void)
{
avl_node *root = NULL;
char ch;
int num;

	do{
		printf("Enter number in new node.\n");
		scanf("%d",&num);
		root = insert_avl(root, num);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	} while(ch == 'y' || ch == 'Y');

	return root;
}

int main()
{
avl_node *root1 = get_avl_tree();
avl_node *root2 = get_avl_tree();

	avl_node *new_root = merge_tree(root1, root2);

	printPreorder(new_root);
	printf("\n");

	return EXIT_SUCCESS;
}
