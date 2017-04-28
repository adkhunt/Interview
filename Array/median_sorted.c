#include<stdio.h>
#define SUCCESS 0
#define SIZE 6

/*
 * Program to find the median of two sorted array
 * using devide and conquor method
 */

/*
 * Return the minimum element
 */

int min(int a, int b)
{
	return a < b ? a : b;
}

/*
 * Return the maximum element
 */

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
 * Get the median of first array.
 */

int median(int arr[], int n)
{
	if(n <= 0)
		return -1;

	if(n%2 == 0)
		return (arr[n/2] + arr[n/2 - 1])/2;

	return arr[n/2];
}

/*
 * Recursively call the function and return 
 * the median of two array
 */

int get_median(int arr1[SIZE], int arr2[SIZE], int n)
{
	if(n <= 0)
		return -1;

	if(n == 1)
		return (arr1[0] + arr2[0]) / 2;

	if(n == 2)
		return ((max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2);

	int median1 = median(arr1, n);
	int median2 = median(arr2, n);

	if(median1 == median2)
		return median1;

	if(median1 > median2)
	{
		if(n%2 == 0)
			return get_median(arr1, arr2 + n/2 -1, n - n/2 + 1);

		return get_median(arr1, arr2 + n/2 , n/2);
	}

	else
	{
		if(n%2 == 0)
			return get_median(arr1 + n/2 - 1, arr2, n - n/2 +1);

		return get_median(arr1 + n/2, arr2, n/2);
	}
}

int main()
{
int arr1[SIZE] = {1, 12, 15, 26, 38};
int arr2[SIZE] = {2, 13, 17, 30, 45};

	int median = get_median(arr1, arr2, SIZE);

	printf("Median = %d\n",median);

	return SUCCESS;
}
