#include<stdio.h>

/*
 * Program to find the type of the array
 * if it is ascending, decending, increasing than
 * decreasing, decreasing than increasing
 */

/*
 * This function will traverse through whole array
 * and check the conditions.
 */

void print_type(int arr[], int size)
{
int i = 0;

	while(arr[i] <= arr[i+1] && i < size)
		++i;

	if(i == size-1)
	{
		printf("Array is Increasing.\n");
		return ;
	}

	if(i != 0 && i != size - 1)
	{
		printf("Array is a ascending rotated.\n");
		return ;
	}

	if(i == 0)
	{
		while(arr[i+1] <= arr[i] && i < size)
			++i;

		if(i == size)
		{
			printf("Array is decreasing.\n");
			return ;
		}

		if(i != 0 && i != size - 1)
		{
			printf("Array is descending rotated.\n");
			return ;
		}
	}
}

int main()
{
int arr1[] = {4, 5, 6, 1, 2, 3};
int arr2[] = {2, 1, 7, 5, 4, 3};
int arr3[] = {1, 2, 3, 4, 5, 8};
int arr4[] = {9, 5, 4, 3, 2, 1};

	print_type(arr1, 6);
	print_type(arr2, 6);
	print_type(arr3, 6);
	print_type(arr4, 6);

	return 0;
}
