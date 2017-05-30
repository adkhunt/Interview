#include<stdio.h>
#define SUCCESS 0
#define ARR_SIZE 11
#define INT_MAX 1 << 30

/*
 * Program to find the minimum jumps required 
 * to reach at the end by using the element
 * of the array
 */

/*
 * this function will start the scanning the array
 * from the last index of the array and check if
 * the element at the last is equql to greater than the
 * size of array if yes than we put 1 else we check
 * in the auxilary array for minimum element.
 */

int count_jumps_to_reach(int arr[ARR_SIZE])
{
int i, min, j, elem;
int result_array[ARR_SIZE] = {0};

	for(i = ARR_SIZE - 2 ; i >= 0 ; --i)
	{
		if(arr[i] + i >= ARR_SIZE - 1)
		{
			result_array[i] = 1;
		}

		else
		{
			j = i+1;
			min = INT_MAX;

			while(j < ARR_SIZE && j <= arr[i] + i)
			{
				if(min > result_array[j])
					min = result_array[j];
				++j;
			}

			result_array[i] = min+1;
		}
	}

	return result_array[0];
}

int main()
{
int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

	int total_jumps = count_jumps_to_reach(arr);

	printf("Total jumps = %d\n",total_jumps);

	return SUCCESS;
}
