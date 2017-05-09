#include<stdio.h>
#include<stdlib.h>
#include"min_heap.h"
#define INT_MAX 1 << 30
#define N 4

/*
 * Program to merge the n sorted array into
 * one array
 */

/*
 * This function merge the n sorted array into 
 * one array with using min heap function
 */

int* merge_n_array(int matrix[N][N])
{
int i;
heap *arr = create_heap(N);
int *result = (int*) malloc(sizeof(int)*(N*N));

	for(i = 0 ; i < N ; ++i)
	{
		arr->heap_array[i].element = matrix[i][0];
		arr->heap_array[i].cur_row = i;
		arr->heap_array[i].next_col = 1;
	}

	build_heap(arr);

	for(i = 0 ; i < N*N ; ++i)
	{
		result[i] = arr->heap_array[0].element;
		
		if(arr->heap_array[0].next_col < N)
		{
			int row = arr->heap_array[0].cur_row;
			int col = arr->heap_array[0].next_col;
			arr->heap_array[0].element = matrix[row][col];
			arr->heap_array[0].next_col += 1;
		}

		else
			arr->heap_array[0].element = INT_MAX;

		min_heapify(arr, 0);
	}

	return result;
}

/*
 * Print the final array which is merged
 */

void print_array(int *arr)
{
int size = N*N, i;

	for(i = 0 ; i < size ; ++i)
		printf("%d ",arr[i]);

	printf("\n");
}

int main()
{
int arr[N][N] = {{1, 5, 8, 9},
		 {2, 3, 7, 10},
		 {4, 6, 11, 15},
		 {2, 4, 6, 9}};

	int *merged_array = merge_n_array(arr);

	print_array(merged_array);

	return EXIT_SUCCESS;
}
