#include<stdio.h>
#include<stdlib.h>

#define ARR_SIZE 9

/*
 * Program to get the maximum sum from the
 * given size of sub array
 */

int get_maxSum (int *arr, int window){

   if (window > ARR_SIZE){
      printf ("Array size is less than window size");
      return 0;
   }

   int i, sum = 0, max = 0;

   for (i = 0 ; i < window ; ++i)
      sum += arr[i];

   max = sum;

   for (i ; i < ARR_SIZE ; ++i){

      sum -= arr[i-window];
      sum += arr[i];

      if (sum > max)
         max = sum;
   }

   return max;
}

int main(){

   int arr[ARR_SIZE] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
   int window = 3;

   int sum = get_maxSum (arr, window);

   printf ("Sum in %d window is %d\n",window,sum);

   return 0;
}
