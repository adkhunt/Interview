#include<stdio.h>
#include<stdbool.h>
#define SIZE 9

/*
 * To find the possibility of getting the sum from 
 * integer array 
 */

/*
 * Function will return the total possible pair
 * which make the sum of given integer
 */

int possible_pair(int arr[SIZE],int sum)
{

	/*
	 * Variable I is iterator which traverse from 
	 * all index in array.
	 * Variable sub will take the substraction from 
	 * sum and current index.
	 */

int i,sub,count = 0;
bool temp[sum]; // Initialise all the array with false

	for(i = 0 ; i < sum ; ++i)
		temp[i] = false;

	/*
	 * Traverse from all array and store the result in temp
	 * bool array
	 */

	for(i = 0 ; i < SIZE ; ++i)
	{
		sub = sum - arr[i];

		if(temp[sub] == true)
			++count;

		else
			temp[arr[i]] = true;
	}

	return count;
}

int main()
{
int arr[SIZE],i,sum;

	/*
	 * prompt the user to scan the array element
	 */

	printf("Enter array element.\n");
	for(i = 0 ; i < SIZE ; ++i)
		scanf("%d",&arr[i]);

	/*
	 * Scan the sum which we are going to find the 
	 * pair in array
	 */

	printf("Enter sum to find the pair.\n");
	scanf("%d",&sum);

	int res = possible_pair(arr,sum);

	/* 
	 * Print the total result in array
	 */

	printf("Total possible pair = %d\n",res);

	return 0;
}
