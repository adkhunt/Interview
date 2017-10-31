#include<stdio.h>
#include<stdlib.h>

struct node{
		int num;
		struct node *right;
		struct node *left;
};

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->right = temp->left = NULL;

	return temp;
}

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

void print_tree(struct node *root)
{
	if(root == NULL)
		return ;

	print_tree(root->left);
	printf("%d ",root->num);
	print_tree(root->right);
}

void largest_bends(struct node *root,char pre, char side, int num, int *max, int cur_max, int *a)
{
	if(root == NULL)
		return ;

	if((pre == 'l' && side == 'r') || (pre == 'r' && side == 'l'))
		cur_max += 1;

	if(*max < cur_max)
	{
		*max = cur_max;
		a[*max] = root->num;
	}

	largest_bends(root->left, side, 'l', root->num, max, cur_max, a);
	largest_bends(root->right, side, 'r', root->num, max, cur_max, a);
}

int count_max_bends(struct node *root, int *arr)
{
	if(root == NULL)
		return 0;

int l_max = 0;
int r_max = 0;

	arr[0] = root->num;

	largest_bends(root->left,'n', 'l',root->num, &l_max, 1, arr);
	largest_bends(root->right, 'n', 'r', root->num, &r_max, 1, arr);

	return l_max > r_max ? l_max : r_max;
}


int main()
{
struct node *root = NULL;
int num, num2, i;
int arr[10];
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

	int res = count_max_bends(root, arr);

	for(i = 0 ; i <= res ; ++i)
		printf("%d ",arr[i]);

	printf("\n");

	return SUCCESS;
}
