#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int max(int a,int b)
{
	return a > b ? a : b;
}

int Longest_Increasing_Sequence(int arr[SIZE])
{
int i,j,hash[SIZE] = {1};

	for(i = 1 ; i < SIZE ; ++i)
	{
		for(j = 0 ; j < i ; ++j)
		{
			if(arr[i] > arr[j] && hash[i] < hash[j]+1)
				hash[i] = hash[j]+1;
		}
	}

	j = hash[0];

	for(i = 1 ; i < SIZE ; ++i)
	{
		j = max(hash[i],j);
	}

	return j;
}

int main()
{
int arr[SIZE],i;

	printf("Enter element in array.\n");
	for(i = 0 ; i  < SIZE ; ++i)
		scanf("%d",&arr[i]);

	int sequence = Longest_Increasing_Sequence(arr);

	printf("Longest Increasing subsequence size is %d\n",sequence);

	return EXIT_SUCCESS;
}
