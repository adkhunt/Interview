#include<stdio.h>
#define SUCCESS 0
#define SIZE 8

/*
 * Program to find the maximum we can make the
 * price of rodes which have different prices
 * so we have to get the maximum from them
 */

/*
 * This function will return the maximum from
 * the two integer
 */

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
 * This is the main function which count the
 * maximum price which can be made from given 
 * parts using one auxilary array
 */

int get_maximum_rodes(int arr[SIZE])
{
int maximum = 0, i, j;
int result[SIZE+1] = {0};

	for(i = 1 ; i <= SIZE ; ++i)
	{
		maximum = 0;
		for(j = 0 ; j < i ; ++j)
		{
			maximum = max(maximum, arr[j] + result[i-j-1]);
		}

		result[i] = maximum;
	}

	for(i = 0 ; i <= SIZE ; ++i)
		printf("%d ",result[i]);
	printf("\n");

	return result[SIZE];
}

int main()
{
int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

	int maxim = get_maximum_rodes(arr);

	printf("Maximum = %d\n",maxim);

	return SUCCESS;
}
