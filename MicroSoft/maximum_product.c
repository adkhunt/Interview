#include<stdio.h>
#define SIZE 7

int my_abs(int num){

   if (num<0)
      return num*(-2)+num;
   return num;
}

int getMaxProd(int *arr, int size){

   int i, cur_prod=1, num, max=0;

   for (i = 0 ; i < size ; ++i){

      num = my_abs(arr[i]);
      cur_prod *= num;
      if (cur_prod > max)
         max = cur_prod;
      if (num == 0)
         cur_prod = 1;
   }

   return max;
}

int main(){

   /*int arr1[SIZE] = {6, -3, -10, 0, 2};
   int arr2[SIZE] = {-1, -3, -10, 0, 60};
   int arr3[SIZE] = {-2, -3, 0, -2, -40};

   printf ("Max = %d\n",getMaxProd(arr1, SIZE));
   printf ("Max = %d\n",getMaxProd(arr2, SIZE));
   printf ("Max = %d\n",getMaxProd(arr3, SIZE));*/

   int arr[SIZE] = {1, -2, -3, 0, 7, -8, -2};
   printf ("Maximum product = %d\n",getMaxProd(arr, SIZE));

   return 0;
}
