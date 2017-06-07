#include<stdio.h>
#define SIZE 7
#define SUCCESS 0

/*
 * Program to get the number which occur
 * odd number of time
 */

/*
 * This function return the number which occur 
 * odd number of time to achieve this we use XOR
 * which finally gets the odd number
 */

int get_odd_number(int arr[])
{
int i, res = 0;

	for(i = 0 ; i < SIZE ; ++i)
		res ^= arr[i];

	return res;
}

int main()
{
int arr[SIZE] = {1, 2, 1, 2, 3, 1, 3};

	int res = get_odd_number(arr);

	printf("Res = %d\n",res);

	return SUCCESS;
}
