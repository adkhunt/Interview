#include<stdio.h>
#include<stdlib.h>

struct node{
		int num;
		struct node *left;
		struct node *right;
		struct node *next;
};

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));

	temp->num = num;
	temp->left = temp->right = temp->next = NULL;

	return temp;
}

void add_node_tree(struct node **root, int num)
{
	if(*root != NULL)
	{
		struct node *pre = *root;
		struct node *cur = *root;

		while(pre != NULL)
		{
			cur = pre;

			if(pre->num > num)
				pre = pre->left;
			else
				pre = pre->right;
		}

		if(cur->num > num)
			cur->left = get_new_node(num);
		else
			cur->right = get_new_node(num);
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

void connect_child(struct node *root, struct node *l_child, struct node *r_child)
{
	if(l_child && r_child)
		l_child->next = r_child;

	if(r_child != NULL)
		r
}

void connect_next_node(struct node *root)
{
	if(root == NULL)
		return ;

struct node *l_child = root->left;
struct node *r_child = root->right;

	connect_child(root, l_child, r_child);
	connect_next_node(root->left);
	connect_next_node(root->right);
}

void print_level(struct node *root)
{
	if(root == NULL)
		return ;

struct node *level = root;

	while(level != NULL)
	{
		printf("%d ",level->num);
		level = level->next;
	}

	printf("\n");
	print_level(root->left);
}

int main()
{
struct node *root = NULL;
char ch;
int num;

	do{
		printf("Enter number in new node.\n");
		scanf("%d",&num);
		add_node_tree(&root, num);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_tree(root);

	printf("\n");

	connect_next_node(root);
	print_level(root);
	printf("\n");

	return SUCCESS;
}
