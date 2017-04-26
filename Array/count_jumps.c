#include<stdio.h>
#define SIZE 6

/*
 * A thief trying to escape from a jail has to 
 * cross ‘N’ walls each with varying heights. 
 * He climbs ‘X’ feet every time. But, due to 
 * the slippery nature of those walls, every 
 * times he slips back by ‘Y’ feet. Now the input 
 * is given as (N, {H1, H2, H3,….Hn}, X, Y}. Calculate 
 * the total number of jumps required to cross all 
 * walls and escape from the jail.
 */

/*
 * Test Case 1 : if thief climb 5 feet and slip back 1 feet.
 * so total jumps are 29.
 * for 29 feet he fall back 5 feet again
 * to cover that 5 feet again he fall back 1 feet
 * so total will be 35 feet
 */

/*
 * Test Case 2 : If x = 2 and y = 1
 * total jumps are 29 feet
 * to cover 29 he fall back 14 feet
 * to cover 14 feet he again fall back 7 feet
 * to cover 7 feet he again fall back 3 feet
 * to cover that 3 feet again fall back 1 feet
 * so total will be 54 feet
 */

/*
 * NOTE : we are neglating floating points.
 */

/*
 * This function will return the total jumps required
 */

float count_jumps(int arr[SIZE], int x, int y)
{
int i, sum = 0, temp;
float res = 0;

	for(i = 0 ; i < SIZE ; ++i)
		sum += arr[i];		// Get the total jumps to required

temp = sum;				// Copy that sum in temp variable

	while(temp > 0)		// We calculate jumps until temp is not zero
	{
		res += ((temp*y)/x);
		temp = (temp*y)/x;
	}

	res += sum;		// Add extra jumps to total jumps
	
	return res;
}

int main()
{
int arr[SIZE] = {2, 4, 7, 1, 6, 9};
int x,y;

	printf("Enter x any y accordingly.\n");
	scanf("%d%d",&x,&y);

	float total_jumps = count_jumps(arr,x,y);

	printf("Total jumps = %f\n",total_jumps);

	return 0;
}
