#include<stdio.h>
#define EXIT_SUCCESS 0
#define SIZE 5
#define INT_MIN 1 << 31
#define INT_MAX 1 << 30

/*
 * Program to get the product from given two array where 
 * return the product of maxmum of first array and minimum of 
 * second array to the main function
 */

int find_result(int arr1[SIZE], int arr2[SIZE])
{
int i;
int min = INT_MAX;
int max = INT_MIN;

	/*
	 * Here we use the same size of the array but
	 * we can use different size for both array and can
	 * use two for loops for finding the minimum from the
	 * second array
	 */

	for(i = 0 ; i < SIZE ; ++i)
	{
		if(max < arr1[i])
			max = arr1[i];

		if(min > arr2[i])
			min = arr2[i];
	}

	return min*max;
}

int main()
{
int arr1[SIZE] = {3, 7, 2, 45, 15};
int arr2[SIZE] = {4, 23, 7, 3, 8};

	int res = find_result(arr1, arr2);

	printf("Product = %d\n",res);

	return EXIT_SUCCESS;
}
