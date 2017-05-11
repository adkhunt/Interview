#include<stdio.h>
#include<stdlib.h>

/*
 * Program to convert the sorted array to
 * balanced binary search tree
 */

/*
 * This structure stored the basic tree node
 */

typedef struct TREE_NODE{
				int *num_addr;
				struct TREE_NODE *left;
				struct TREE_NODE *right;
} tree_t;

/*
 * This function return the new node to
 * the calling function
 */

tree_t* get_new_node(int *num)
{
	tree_t *temp = (tree_t*) malloc(sizeof(tree_t));

	temp->num_addr = num;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/*
 * Recursively devide the array into half 
 * get the middle element and make it root
 * and in left side insert left part of array
 * and right side right part and repeat the 
 * process recursively
 */

tree_t* get_tree_from_array(int *array, int start, int end)
{
tree_t *root = NULL;

	if(start > end)
	{
		return root;
	}

	int mid = (start+end)/2;

	root = get_new_node(array+mid);

	root->left = get_tree_from_array(array, start, mid-1);
	root->right = get_tree_from_array(array, mid+1, end);

	return root;
}

/*
 * Print the tree in preorder fashion
 */

void print_preorder(tree_t *root)
{
	if(root == NULL)
		return;

	printf("%d ",*(root->num_addr));
	print_preorder(root->left);
	print_preorder(root->right);
}

int main()
{
int *sorted_array = NULL;
int size, i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	sorted_array = (int*) malloc(sizeof(int)*size);

	printf("Enter element in array.\n");
	for(i = 0 ; i < size ; ++i)
		scanf("%d",&sorted_array[i]);

	tree_t *root = get_tree_from_array(sorted_array, 0, size-1);

	print_preorder(root);
	printf("\n");

	return EXIT_SUCCESS;
}
