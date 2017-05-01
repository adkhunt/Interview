#include<stdio.h>
#include<stdlib.h>

/*
 * Program to fill the matrix with respective 
 * ancentor. total nodes in tree are 1 to N
 * with containig 1 to N numbers. if mat[A][B] = 1
 * if A is the Ancentor of B else we put 0.
 */

/*
 * Tree nodes contain with one integer and two
 * self referencial pointer.
 */

typedef struct NODE{
			int num;
			struct NODE *right;
			struct NODE * left;
} node;

/*
 * Pair structure which hold size and the 
 * pointer to matrix which holds the data
 */

typedef struct PAIR{
			int size;
			int **matrix;
} pair;

/*
 * Return the node of tree with basic 
 * initialisation
 */

node* get_new_node(int num)
{
	node *temp = (node*) malloc(sizeof(node));

	temp->num = num;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

/*
 * Count the total node in the binary tree
 */

int count_node(node *root)
{
	if(root == NULL)
		return 0;

int count = 1;

	count += count_node(root->left);
	count += count_node(root->right);

	return count;
}

/*
 * Fill the row with anceentor which is passed
 * in the parameter
 */

void fill_matrix(node *root, int **arr, int main_row)
{
	if(root == NULL)
		return;

	arr[main_row][root->num] = root->num != main_row;
	fill_matrix(root->left, arr, main_row);
	fill_matrix(root->right, arr, main_row);
}

/*
 * Fill the matrix main util function
 */

void matrix_fill_util(node *root, int **matrix)
{
	if(root == NULL)
		return ;

	fill_matrix(root, matrix, root->num);
	matrix_fill_util(root->left, matrix);
	matrix_fill_util(root->right, matrix);
}

/*
 * This function will allocate the dynamic 
 * memory for matrix with total nodes in the
 * binary tree and intialise with zero
 */

pair fill_ancentor_matrix(node *root)
{
int total_node = count_node(root);
int **matrix = (int**) malloc(sizeof(int*)*total_node);
int i;

	printf("TOTAL NODE = %d\n",total_node);

	for(i = 0 ; i < total_node ; ++i)
		matrix[i] = (int*) calloc(total_node, sizeof(int));

	matrix_fill_util(root, matrix);

	pair ret = {total_node, matrix};
	return ret;
}

/*
 * Print the matrix 
 */

void print_matrix(int **matrix, int size)
{
int i,j;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = 0 ; j < size ; ++j)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

int main()
{
node *root = NULL;

	root = get_new_node(0);
	root->left = get_new_node(1);
	root->left->left = get_new_node(3);
	root->left->left->left = get_new_node(7);
	root->left->left->right = get_new_node(8);
	root->left->right = get_new_node(4);
	root->left->right->left = get_new_node(9);
	root->right = get_new_node(2);
	root->right->left = get_new_node(5);
	root->right->right = get_new_node(6);
	

	pair result = fill_ancentor_matrix(root);

	print_matrix(result.matrix, result.size);

	return EXIT_SUCCESS;
}
