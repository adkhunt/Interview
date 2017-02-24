#include<stdio.h>
#include<stdio.h>
#define SIZE 8

//////////////////////////////////////////////////
//						//
// Program to find the kadanes algorithms (find //
// Maximum sum sub-array in int array		//
//						//
//////////////////////////////////////////////////

int kadanes_algorithm(int a[SIZE])
{
int i,largest_sum = -1,sum = 0;

	for(i = 0 ; i < SIZE ; ++i)
	{
		sum += a[i];

		if(sum < 0)
			sum = 0;

		else if(largest_sum < sum)
			largest_sum = sum;
	}

	return largest_sum;
}

int main()
{
int arr[SIZE],i;

	printf("Enter element in array.\n");
	for(i = 0 ; i < SIZE ; ++i)
		scanf("%d",&arr[i]);

	int sum = kadanes_algorithm(arr);

	printf("Largest sum sub-array = %d\n",sum);

	return 0;
}
