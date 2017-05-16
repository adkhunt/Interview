#include<stdio.h>
#define SIZE 8

/*
 * Program to get contigues sub-array
 * which has the maximum sum
 */

/*
 * Return the maximum sum from the given array
 */

int get_max_sum(int arr[SIZE])
{
int i, cur_sum = arr[0], max_sum = 0;

	for(i = 0 ; i < SIZE ; ++i)
	{
		cur_sum += arr[i];

		if(cur_sum < 0)
			cur_sum = 0;

		if(max_sum < cur_sum)
			max_sum = cur_sum;
	}

	return max_sum;
}

int main()
{
int arr[SIZE] = {-2, -3, 4, -1, -2, 1, 5, -3};

	int sum = get_max_sum(arr);

	printf("sum = %d\n",sum);

	return 0;
}
