#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

/*
 * Program to sort the strings according to 
 * length
 */

/*
 * Return the length of the string
 */

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

/*
 * Swap two integers value
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Sort the integer array using bubble sort
 */

void sort_array(int arr[][SIZE],int size)
{
int i,j;

	for(i = 0 ; i < SIZE - 1 ; ++i)
	{
		for(j = 0 ; j < SIZE - i - 1; ++j)
		{
			if(arr[0][j] > arr[0][j+1])
			{
				swap(&arr[0][j],&arr[0][j+1]);
				swap(&arr[1][j],&arr[1][j+1]);
			}
		}
	}
}

/*
 * This is the main function which we call from 
 * main which perform all task
 */

void print_sorted_length(char **str, int size)
{
int arr[2][SIZE],i;

	for(i = 0 ; i < SIZE ; ++i)
	{
		arr[0][i] = my_strlen(str[i]);
		arr[1][i] = i;
	}

	sort_array(arr, SIZE);

	for(i = 0 ; i < SIZE ; ++i)
		printf("%s ",str[arr[1][i]]);
	printf("\n");
}

int main()
{
char* str[] = {"India","I","from","am"};

	print_sorted_length(str, SIZE);

	return EXIT_SUCCESS;
}
