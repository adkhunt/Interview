#include<stdio.h>
#define SUCCESS 0
#define N 4

/*
 * Program to find the path which visit all 
 * the stations
 */

/*
 * Structure variable that holds two integer petrol
 * and second is distance from that bunk to next petrol bunk
 */

struct PAIR{
		int petrol,distance;
};

/*
 * Typedef to the pair 
 */

typedef struct PAIR pair;

/*
 * This function return the starting index in the array
 * of the pair
 */

/*
 * We keep track of the total petrol which saved after
 * reaching the next petrol bunk. if the total of that
 * petrol is less than zero than we will update the start 
 * to the next index
 */

int find_start_point(pair arr[N])
{
int start = 0, i, total = 0;

	for(i = 0 ; i < N ; ++i)
	{
		total += arr[i].petrol - arr[i].distance;
		
		if(total < 0)
		{
			start = i + 1;
			total = 0;
		}
	}

	if(start < N && total >= 0)
		return start;
	else
		return -1;
}

int main()
{
pair arr[N] = {{4, 6},{6, 5},{7, 3},{4, 5}};

	int start = find_start_point(arr);
	printf("Start from %d\n",start);

	return SUCCESS;
}
