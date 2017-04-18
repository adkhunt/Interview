#include<stdio.h>

/*
 * Program to fine the pivot element in the
 * unsorted array in O(n) time. pivot means
 * the element which all left element are smaller
 * than that and all right element are greater
 * than that.
 */

/*
 * Return the minimum element between
 * two element
 */

int min(int a,int b)
{
	return a < b ? a : b;
}

/*
 * Return maximum element from two 
 * element
 */

int max(int a,int b)
{
	return a > b ? a : b;
}

/*
 * Return the pivot element in the unsorted
 * array we use two auxilary array to store 
 * minimum and maximum from left side and right
 * size respectively and return the common element
 * in both array.
 */

int find_pivot(int arr[],int size)
{
int i, left_array[size], right_array[size];

	left_array[0] = arr[0];
	right_array[size-1] = arr[size-1];

	for(i = 1 ; i < size ; ++i)
	{
		left_array[i] = max(left_array[i-1], arr[i]);
		right_array[size-i-1] = min(right_array[size-i], arr[size-i-1]);
	}

	for(i = 0 ; i < size ; ++i)
		printf("%d ",arr[i]);
	printf("\n");

	for(i = 0 ; i < size ; ++i)
	{
		if(left_array[i] == right_array[i])
			return i;
	}

	return -1;
}

int main()
{
int arr[] = {3, 1, 5, 2, 4, 8, 11, 13, 9, 12, 10};
int size = sizeof(arr)/sizeof(arr[0]);

	int pivot = find_pivot(arr,size);

	if(pivot != -1)
		printf("%d is the pivot\n",arr[pivot]);

	else
		printf("No pivot possible.\n");

	return 0;
}
