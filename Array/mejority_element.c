#include<stdio.h>
#define SIZE 9

/*
 * Program to find the mejority element in the 
 * array which occur more than size/2 time. To
 * solve we use moore's voting algorithm.
 */

/*
 * This function will return the element
 * which occur more time compare to other 
 * element
 */

int get_element(int arr[SIZE])
{
int i, max_ind = 0, count =1;

	for(i = 1 ; i < SIZE ; ++i)
	{
		if(arr[max_ind] == arr[i])
			++count;

		else
			--count;

		if(count == 0)
		{
			count = 1;
			max_ind = i;
		}
	}

	return arr[max_ind];
}

/*
 * This function will return the actual element
 * which occur more than size/2 time
 */

int find_mejority(int arr[SIZE])
{
int i,count = 0;

	int elem = get_element(arr);

	for(i = 0 ; i < SIZE ; ++i)
	{
		if(arr[i] == elem)
			++count;
	}

	if(count > SIZE/2)
		return elem;

	else
		return -1;
}

int main()
{
int arr[SIZE] = {1, 2, 3, 1, 1, 1, 4, 3, 1};

	int elem = find_mejority(arr);

	if(elem != -1)
		printf("Mejority element = %d\n",elem);

	else
		printf("No mejority element found.\n");

	return 0;
}
