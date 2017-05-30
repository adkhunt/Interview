#include<stdio.h>
#define SUCCESS 0
#define INT_MIN 1<<31
#define N 7

/*
 * Program to maximize number of 0s by 
 * flipping a subarray
 */

/*
 * Return the maximum element from two element
 */

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
 * This function return the total result of 
 * array. Here we use zero and one count if
 * element is one than we increment one_count
 * variable if its zero than we increment zero
 * count and make one_count zero so we can get 
 * continuos array of ones
 */

int get_flip(int arr[N])
{
int i, zero_count = 0;
int  one_count = 0, max_array = INT_MIN;

	for(i = 0 ; i < N ; ++i)
	{
		if(arr[i] == 0)
		{
			++zero_count;
			one_count = 0;
		}

		else
		{
			++one_count;
			max_array = max(one_count, max_array);
		}
	}

	return zero_count+max_array;
}

int main()
{
int arr[N] = {0, 1, 0, 0, 1, 1, 0};

	int res = get_flip(arr);

	printf("We can get %d zeros\n",res);

	return SUCCESS;
}
