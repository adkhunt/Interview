#include<stdio.h>
#include<stdlib.h>

/*
 * Program to convert doubly linked list to 
 * binary tree inplace in O(n) time
 */

/*
 * structure variable to store data and two
 * self referencial structure
 */

struct node{
		int num;
		struct node *pre;
		struct node *next;
};

/*
 * return the node which is required to the 
 * adding into linked list with some basic 
 * initialization
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = temp->pre = NULL;

	return temp;
}

/*
 * Function to add new node at the end into the 
 * doubly linked list
 */

void add_node(struct node **hptr)
{
int num;

	printf("Enter number to new node.\n");
	scanf("%d",&num);

static struct node *pre = NULL;

	if(*hptr)
	{
		pre->next = get_new_node(num);
		pre = pre->next;
	}

	else
	{
		*hptr = get_new_node(num);
		pre = *hptr;
	}
}

/*
 * Function to print the doubly linked list
 */

void print_list(struct node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

/*
 * This is the main function which will convert 
 * the linklist to the binary search tree
 */

struct node* convert_list(struct node **hptr,int node_count)
{
	if(node_count <= 0)
		return NULL;

	struct node *left = convert_list(hptr,node_count/2);

	struct node *root = *hptr;

	root->pre = left;

	*hptr = (*hptr)->next;

	root->next = convert_list(hptr,node_count/2-1);

	return root;
}

/*
 * Return the total nodes in the doubly linked
 * list
 */

int get_node_count(struct node *hptr)
{
int count = 0;

	while(hptr)
	{
		++count;
		hptr = hptr->next;
	}

	return count;
}

/*
 * This is the function which user will call
 * to convert double linked list to the binary
 * search tree
 */

struct node* dll_to_tree(struct node **hptr)
{
	int node_count = get_node_count(*hptr);

	return convert_list(hptr,node_count);
}

/*
 * This function will return the height of 
 * the binary search tree
 */

int get_height(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = get_height(root->pre) + 1;
	int rh = get_height(root->next) + 1;

	return lh > rh ? lh : rh;
}

/*
 * This function will print the level which is 
 * passed in the function parameter
 */

void print_cur_level(struct node *root,int level_to_print,int cur_level)
{
	if(root == NULL)
		return;

	if(level_to_print == cur_level)
		printf("%d ",root->num);

	print_cur_level(root->pre,level_to_print,cur_level+1);
	print_cur_level(root->next,level_to_print,cur_level+1);
}

/*
 * This is the function which will called by user
 * in the program to print the level order tree
 */

void print_tree_level(struct node *root)
{
	int height = get_height(root);

int i;

	for(i = 0 ; i <= height ; ++i)
	{
		print_cur_level(root,i,0);
		printf("\n");
	}
}

int main()
{
struct node *hptr = NULL;
char ch;

	do{
		add_node(&hptr);
		printf("Do you want o continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);

	struct node *root = dll_to_tree(&hptr);

	printf("Level order of binary search tree.\n");

	print_tree_level(root);

	return EXIT_SUCCESS;
}
