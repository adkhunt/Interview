#include<stdio.h>
#define SIZE 6

/*
 * There are n bags containing different amount of chocolates 
 * and there is wizard and a kid.At every second a kid eat all 
 * the chocolates from bag containing maximum number of chocolates 
 * and wizard refills it with the half the chocolates it was containing.
 * Find how many chocolates does the kid has eaten at t seconds.
 */

/*
 * This function will return the maximum in the
 * integer array
 */

int get_max(int arr[SIZE])
{
int i, max = arr[0];

	for(i = 1 ; i < SIZE ; ++i)
	{
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

/*
 * Count the chocolate eaten by kid in t second
 */

int count_chocolate(int bags[SIZE], int second)
{
int i, count = 0;

	int max = get_max(bags);

	for(i = 0 ; i < second ; ++i)
	{
		count += max;

		max = max/2;
	}

	return count;
}

int main()
{
int bags[SIZE] = {200,1400,600,150,50,750}; // Bags contain chocolate
int second;

	printf("Enter second to get chocolate count.\n");
	scanf("%d",&second);

	int total_chocolate = count_chocolate(bags, second);

	printf("Total chocolate eaten by kid in %d second is %d\n",second,total_chocolate);

	return 0;
}
