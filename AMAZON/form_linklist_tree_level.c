#include<stdio.h>
#include<stdlib.h>

/*
 * Given a binary tree. Add links in binary tree in such a way,
 * that all the nodes on a level form a linked list.
 */

typedef struct node{

                    int num;
                    struct node *right;
                    struct node *left;
                    struct node *next;
} node;

node* get_new_node (int num)
{
   node *new_node = (node*) malloc(sizeof(node));

   new_node->num = num;
   new_node->left = new_node->right = new_node->next = NULL;

   return new_node;
}

/*
 * Add new node in the given binary tree
 */

void add_node(node **root, int num){

   if (*root == NULL){
      *root = get_new_node(num);
      return;
   }

   if ((*root)->num > num)
      add_node(&(*root)->left, num);
   else
      add_node(&(*root)->right, num);
}

/*
 * Create a binary tree with given elements in array
 */

void get_tree(node **root){

   int array[] = {10, 7, 4, 3, 6, 1, 15, 14, 25, 22, 28};
   int size = 11, i;

   for (i = 0 ; i < size ; ++i)
      add_node (root, array[i]);
}

int getHeight (node *root)
{

   if (root == NULL)
      return 0;

   int left_height = 1 + getHeight(root->left);
   int right_height = 1 + getHeight(root->right);

   return left_height > right_height ? left_height : right_height;
}

/*
 * Main function which will create the links in the 
 * tree node at same level
 */

void connectNodeLevel (node *root, int cur_level, node **array){

   if (root == NULL)
      return;

   if (array[cur_level]){
      array[cur_level]->next = root;
   }

   array[cur_level] = root;

   connectNodeLevel (root->left, cur_level + 1, array);
   connectNodeLevel (root->right, cur_level + 1, array);

}

/*
 * Wrapper function to create a link at the same level
 */

void makeList (node *root){

   int height = getHeight(root);

   node **array = (node**) malloc(sizeof(node*)*height);

   connectNodeLevel (root, 0, array);
}

void print_tree (node *root){

   if (root == NULL)
      return ;

   print_tree(root->left);
   printf ("%d ",root->num);
   print_tree (root->right);
}

void print_list(node *root, int cur_level, int *level){

   if (root == NULL)
      return ;

   node *temp = root;
   if (cur_level > *level){
      while(temp){

         printf ("%d ",temp->num);
         temp = temp->next;
     }

      printf ("\n");
      *level = cur_level;
  }

  print_list(root->left, cur_level + 1, level);
  print_list(root->right, cur_level + 1, level);
}

void print_list_in_tree (node *root){

   if (root == NULL)
      return;

   int level = -1;
   print_list (root, 0, &level);
}

int main()
{
node *root = NULL;

   get_tree(&root);
   print_tree(root);
   printf ("\n\n");
   makeList (root);
   print_list_in_tree(root);

   return 0;
}
