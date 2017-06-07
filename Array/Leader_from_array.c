#include<stdio.h>
#define SUCCESS 0
#define SIZE 6

/*
 * Program to print the leader in given integer array
 * where element is greater than its neighbour
 */

/*
 * This function print the leader in array
 */

void print_leader(int arr[])
{
int i = SIZE - 1, max = arr[i];

	while(i >= 0)
	{
		if(arr[i] > max)
		{
			printf("%d ",arr[i]);
			max = arr[i];
		}

		--i;
	}

	printf("\n");
}

int main()
{
int arr[] = {16, 17, 3, 4, 5, 2};

	print_leader(arr);

	return SUCCESS;
}
