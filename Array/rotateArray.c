#include<stdio.h>

void rotateArray(int *array, int size, int k){

int i, j, temp;

   for (i = 0, j = k -1 ; i < j ; ++i, --j){

      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }

   for (i = k, j = size - 1; i < j ; ++i, --j){

      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }

   for ( i = 0, j = size - 1 ; i < j ; ++i, --j){

      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
   }
}

int main(){

int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = 10;
int rotateBy, i;

   printf ("Enter the k to rotate array\n");
   scanf ("%d",&rotateBy);

   rotateArray(array, size, rotateBy);

   for (i = 0 ; i < size ; ++i)
      printf ("%d ",array[i]);

   printf ("\n");

   return 0;
}
