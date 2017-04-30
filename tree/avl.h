#ifndef AVL
#define AVL

typedef struct AVL_NODE{
			int num;
			int height;
			struct AVL_NODE *right;
			struct AVL_NODE *left;
}avl_node;

avl_node* get_avl_node(int num)
{
	avl_node *temp = (avl_node*) malloc(sizeof(avl_node));

	temp->num = num;
	temp->height = 0;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(avl_node *root)
{
	if(root != NULL)
		return root->height;

	return 0;
}

int get_height(avl_node *root)
{
	return max(height(root->left), height(root->right)) + 1;
}

int get_balance(avl_node *root)
{
	return (height(root->left) - height(root->right));
}

avl_node* rotate_right(avl_node *root)
{
	avl_node *new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;

	new_root->height = get_height(root);
	root->height = get_height(root);

	return new_root;
}

avl_node* rotate_left(avl_node *root)
{
	avl_node *new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;

	new_root->height = get_height(root);
	root->height = get_height(root);

	return new_root;
}

avl_node* insert_avl(avl_node *root, int num)
{
	if(root == NULL)
		return get_avl_node(num);

	if(root->num > num)
		root->left = insert_avl(root->left, num);

	else if(root->num < num)
		root->right = insert_avl(root->right, num);

	else 
		return root;


	root->height = get_height(root);

	int balance = get_balance(root);

	if(balance < -1 && root->right->num < num)
		return rotate_left(root);

	else if(balance < -1 && root->right->num > num)
	{
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}

	else if(balance > 1 && root->left->num < num)
	{
		root->left = rotate_left(root->left);
		return rotate_right(root);
	}

	else if(balance > 1 && root->left->num > num)
	{
		return rotate_right(root);
	}

	return root;
}

void printInorderIterative(avl_node *root)
{

	while(root)
	{
		if(root->left == NULL)
		{
			printf("%d ",root->num);
			root = root->right;
		}

		else
		{
			avl_node *temp = root->left;

			while(temp->right != NULL && temp->right != root)
				temp = temp->right;

			if(temp->right == NULL)
			{
				temp->right = root;
				root = root->left;
			}

			else if(temp->right == root)
			{
				temp->right = NULL;
				printf("%d ",root->num);
				root = root->right;
			}
		}
	}
}

void printPreorder(avl_node *root)
{
	if(root == NULL)
		return;

	printf("%d ",root->num);
	printPreorder(root->left);
	printPreorder(root->right);
}

#endif
