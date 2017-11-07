#include<stdio.h>
#include<stdlib.h>

/*
 * Program to find the path in tree which contain
 * highest bends.
 */

/*
 * This structure is common for node to hold data and
 * pointer to its children
 */

struct node{
		int num;
		struct node *right;
		struct node *left;
};

/*
 * This function return the new created node
 * with basic initialization
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->right = temp->left = NULL;

	return temp;
}

/*
 * This function add the node in the tree
 */

void add_node_tree(struct node **root, int num)
{
	
	if(*root != NULL)
	{
		struct node *pre = *root;
		struct node *cur = *root;

		while(cur !=  NULL)
		{
			pre = cur;

			if(cur->num >= num)
				cur = cur->left;

			else
				cur = cur->right;
		}

		if(pre->num >= num)
			pre->left = get_new_node(num);

		else
			pre->right = get_new_node(num);
	}

	else
		*root = get_new_node(num);
}

/*
 * Print the tree in in-order manner
 */

void print_tree(struct node *root)
{
	if(root == NULL)
		return ;

	print_tree(root->left);
	printf("%d ",root->num);
	print_tree(root->right);
}

/*
 * This function keep track of the bends in tree and
 * fill that path in the array so it's easy to print 
 * that path
 */

void largest_bends(struct node *root,char pre, char side, int num, int *max, int cur_max, int *a)
{
	if(root == NULL)
		return ;

	if((pre == 'l' && side == 'r') || (pre == 'r' && side == 'l'))
		cur_max += 1;

	if(*max < cur_max)
	{
		a[*max] = num;
		a[*max+1] = root->num;
		*max = cur_max;
	}

	largest_bends(root->left, side, 'l', root->num, max, cur_max, a);
	largest_bends(root->right, side, 'r', root->num, max, cur_max, a);
}

/*
 * This function print the array which is filled with path
 */

void print_arr(int *arr, int size)
{
int i = 0;

	for(i = 0 ; i <= size ; ++i)
		printf("%d ",arr[i]);

	printf("\n");
}

/*
 * This is the main function which is called by tha main 
 * funtion and this function internally calls th largest_bend
 * function
 */

void count_max_bends(struct node *root)
{
	if(root == NULL)
		return ;

int l_max = 0;
int r_max = 0;
int l_arr[10], r_arr[10];

	largest_bends(root->left,'n', 'l',root->num, &l_max, 1, l_arr);
	largest_bends(root->right, 'n', 'r', root->num, &r_max, 1, r_arr);

	if(l_max < r_max)
		print_arr(r_arr, r_max);

	else
		print_arr(l_arr, l_max);
}


int main()
{
struct node *root = NULL;
int num, num2, i;
char ch;

	do{
		printf("Enter number to insert in tree.\n");
		scanf(" %d",&num);
		add_node_tree(&root, num);

		printf("Do you want to continue?[y/Y] ");
		scanf("%c",&ch);
	
	}while(ch == 'y' || ch == 'Y');

	print_tree(root);
	printf("\n");

	count_max_bends(root);

	printf("\n");

	return SUCCESS;
}
