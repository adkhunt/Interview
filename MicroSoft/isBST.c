#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

bool isBST (struct node *root){

   if (root == NULL)
      return true;

   if (root->left == NULL && root->right == NULL)
      return true;

   if (root->left && root->left->num > root->num)
      return false;

   else if (root->right && root->right->num < root->num)
      return false;

   if (!isBST(root->left) || !isBST(root->right))
      return false;

   return true;
}

int main(){

   struct node *root = NULL;
   getReadyTree(&root);

   if(isBST(root)){

      printf ("Given tree is binary tree..\n");
   }else{

      printf ("Given tree is not binary tree..\n");
   }

   return 0;
}
