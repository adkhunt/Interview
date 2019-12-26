#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

void printSum (struct node *root, int *sum){

   if (root == NULL)
      return ;

   printSum(root->right, sum);
   printf ("%d ",*sum);
   *sum += root->num;
   printSum(root->left, sum);
}

int main(){

   struct node *root = NULL;
   int sum = 0;

   getReadyTree(&root);
   printInorderRecursive(root);
   printf ("\n");

   printSum(root, &sum);
   printf ("\n");

   return 0;
}
