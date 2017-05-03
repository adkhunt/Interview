#include<stdio.h>
#define SUCCESS 0
#define NA -1
#define N 9
#define M 4

/*
 * Merge an array of size n into another 
 * array of size m+n
 */

/*
 * Below function will swap the values
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Below function will print the array
 */

void print_array(int arr[])
{
int i;

	for(i = 0 ; i < N ; ++i)
		printf("%d ",arr[i]);

	printf("\n");
}

/*
 * This function will move the element of
 * the array at the last which are real number
 */

void move_elem_last(int arr[])
{
int i = N-1;
int j = N-1;

	while(i >= 0)
	{
		if(arr[i] != NA)
		{
			swap(arr+i, arr+j);
			--i, --j;
		}

		else
			--i;
	}
}

/*
 * Main merge function which will merge the
 * array into one
 */

void merge_array(int arr1[], int arr2[])
{
	move_elem_last(arr1);

int i = M, j = 0, k = 0;

	while(i < N && j < M)
	{
		if(arr1[i] < arr2[j])
		{
			arr1[k++] = arr1[i];
			++i;
		}

		else
		{
			arr1[k++] = arr2[j];
			++j;
		}
	}

	while(j < M)
	{
		arr1[k++] = arr2[j++];
	}
}

int main()
{
int arr1[N] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
int arr2[M] = {5, 7, 9, 25};

	merge_array(arr1, arr2);
	print_array(arr1);

	return SUCCESS;
}
