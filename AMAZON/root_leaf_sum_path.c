#include<stdio.h>
#include<stdlib.h>

/*
 * Given a binary tree. Find if there is path from
 * root to leaf with given sum X
 */

typedef struct node{

                    int num;
                    struct node *left;
                    struct node *right;
} node;

node* get_new_node(int num){

   node *new_node = (node*) malloc(sizeof(node));

   new_node->num = num;
   new_node->right = NULL;
   new_node->left = NULL;

   return new_node;
}

void add_new_node(node **root, int num){

   if (*root == NULL){

      *root = get_new_node(num);
      return ;
   }

   else if ((*root)->num > num)
      add_new_node(&(*root)->left, num);
   else
      add_new_node(&(*root)->right, num);
}

node* get_tree(){

   int num;
   char option;
   node *root = NULL;

   do{
      printf("Enter number in new node.\n");
      scanf("%d",&num);
      add_new_node(&root, num);
      printf("Do you want to continue?(y/Y)");
      scanf(" %c",&option);
   }while(option == 'Y' || option == 'y');

   return root;
}

int getHeight(node *root){

   if (root == NULL)
      return 0;

   int leftHeight = 1 + getHeight(root->left);
   int rightHeight = 1 + getHeight(root->right);

   return leftHeight > rightHeight ? leftHeight : rightHeight;
}

void get_root_leaf_sum (node *root, int curSum, int level, int *sumArray, const int sum){

   if (root == NULL)
      return;

   sumArray[level] = root->num;

   if ( (!root->left && !root->right) && curSum + root->num == sum ){

      int i;
      for (i = 0 ; i <= level ; ++i)
         printf("%d ",sumArray[i]);
      printf ("\n");
      return;
   }

   get_root_leaf_sum(root->left, root->num + curSum, level + 1, sumArray, sum);
   get_root_leaf_sum(root->right, root->num + curSum, level + 1, sumArray, sum);
}

void getSumPath(node *root, int sum)
{
/*
 * Array to store the previous elements of the tree
 * to print all the possible path
 */
int *pathArray = calloc((getHeight(root) + 1), sizeof(int));

   get_root_leaf_sum (root, 0, 0, pathArray, sum);
}

void printTree (node *root){

   if (root == NULL)
      return ;

   printTree(root->left);
   printf ("%d ",root->num);
   printTree(root->right);
}

int main(){

   node *root = get_tree();

   printTree(root);
   int num;
   printf ("Enter number to find total sum in tree.\n");
   scanf ("%d",&num);

   getSumPath (root, num);

   return 0;
}
