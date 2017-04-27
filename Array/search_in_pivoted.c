#include<stdio.h>
#define EXIT_SUCCESS 0
#define SIZE 9

/*
 * Program to search the element in pivoted and 
 * rotated array
 */

/*
 * This function will return the pivot index
 * in O(log n) time
 */

int get_pivot(int arr[SIZE], int start, int end)
{
	if(start > end)
		return -1;

	if(start == end)
		return start;

int mid = (start + end) / 2;

	if(mid < end && arr[mid] > arr[mid+1])
		return mid;

	else if(mid > start && arr[mid] < arr[mid-1])
		return mid-1;

	if(arr[start] >= arr[mid])
		return get_pivot(arr,start, mid-1);

	return get_pivot(arr, mid+1, end);
}

/*
 * Search the element in the array using 
 * binary search
 */

int binary_search(int arr[SIZE], int start, int end, int key)
{
	if(start > end)
		return -1;

int mid = (start + end) / 2;

	if(arr[mid] == key)
		return mid;

	if(arr[mid] > key)
		return binary_search(arr,start,mid-1, key);

	return binary_search(arr,mid+1,end,key);
}

/*
 * This is the main function which will search the element
 * in the array
 */

int search_element(int arr[SIZE], int key)
{
	if(arr[0] == key)
		return 0;

	if(arr[SIZE-1] == key)
		return SIZE-1;

	int pivot = get_pivot(arr,0, SIZE);

	if(arr[pivot] == key)
		return pivot;

	if(arr[0] < key && arr[pivot] > key)
		return binary_search(arr,0,pivot-1,key);

	return binary_search(arr,pivot+1,SIZE, key);
}

int main()
{
int arr[SIZE] = {5,6,7,8,9,10,1,2,3};
int key;

	printf("Enter element to search in array.\n");
	scanf("%d",&key);

	int index = search_element(arr,key);

	if(index >= 0)
		printf("Index = %d\n",index);

	else
		printf("No element is present.\n");


	return EXIT_SUCCESS;
}
