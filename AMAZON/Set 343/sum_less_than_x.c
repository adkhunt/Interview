#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

/*
 * Program to print the pair in sorted array
 * which sum is less than given sum
 */

/*
 * This function scanf the array from right
 * and from left side if sum is less than given 
 * number it will print and incerement the left
 * and decrement right side else if res is greater 
 * then result decrement the right side else 
 * increment the left side
 */

void print_pairs(int arr[SIZE], int sum)
{
int i = 0, j = SIZE -1, res = 0;

	while(i < j)
	{
		res = arr[i] + arr[j];

		if(res < sum)
		{
			printf("%d and %d\n",arr[i],arr[j]);
			++i, --j;
		}

		else if(res < sum)
			++i;

		else
			--j;
	}
}

int main()
{
int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int sum;

	printf("Enter sum to find pairs.\n");
	scanf("%d",&sum);

	print_pairs(arr,sum);

	return EXIT_SUCCESS;
}
