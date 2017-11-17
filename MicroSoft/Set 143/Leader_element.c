#include<stdio.h>

/*
 * Program to print the leader element in array 
 * Leader means greater element in array from right
 * side till now.
 */

/*
 * This function will print the leader in array
 * In this function we start scanning the array
 * from the right side and compare if the current
 * element is the greater than till visited or not
 * if yes than print that element.
 */

void print_leader_in_array(int arr[], int size)
{
int i, max;

	printf("%d ",arr[size-1]);
	max = arr[size-1];

	for(i = size -2 ; i >= 0 ; --i)
	{
		if(arr[i] > max)
		{
			printf("%d ",arr[i]);
			max = arr[i];
		}
	}

	printf("\n");
}

int main()
{
int arr[] = {16, 17, 4, 3, 5, 2};

	print_leader_in_array(arr, 6);

	return SUCCESS;
}
