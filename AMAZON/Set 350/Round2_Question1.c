#include<stdio.h>
#include<stdlib.h>

#define INT_MIN -65535
#define INT_MAX 65535

#define ROW 3
#define COL 3

/*
 * Program to find the minimum range which range
 * cover all the row's element. To approach we use
 * min heap concept of merge k sorted array into one
 * array
 */

/*
 * Structure varialbe that holds the element and row 
 * and next coloum which we load after getting the 
 * minimum from the min heap
 */

struct HEAP_NODE{
			int element;
			int row, col;
};

/*
 * This structure variable holds the limit of 
 * heap array and heap node pointer 
 */

struct HEAP{
		int limit;
		struct HEAP_NODE *h_arr;
};

typedef struct HEAP heap;

/*
 * This function will create the heap array of 
 * given size and return the heap pointer to the 
 * heap
 */

heap* create_heap(int size)
{
	heap *temp = (heap*) malloc(sizeof(heap));

	temp->limit = size;
	temp->h_arr = (struct HEAP_NODE*) malloc(sizeof(struct HEAP_NODE)*size);

	return temp;
}

/*
 * This function will swap the two nodes of heap aray
 */

void swap(struct HEAP_NODE *a, struct HEAP_NODE *b)
{
	struct HEAP_NODE temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * This function create the min heap from the array
 */

void min_heapify(heap *arr, int index)
{
	int parent = index;
	int left_child = (parent*2)+1;
	int right_child = (parent*2)+2;

	if(left_child < arr->limit &&
		arr->h_arr[left_child].element < arr->h_arr[parent].element)
		parent = left_child;

	if(right_child < arr->limit &&
		arr->h_arr[right_child].element < arr->h_arr[parent].element)
		parent = right_child;

	if(parent != index)
	{
		swap(&arr->h_arr[parent], &arr->h_arr[index]);
		min_heapify(arr, parent);
	}
}

/*
 * This function construct min heap of full array
 */

void build_min_heap(heap *arr)
{
int i = (arr->limit/2)-1;

	for(i ; i >= 0 ; --i)
		min_heapify(arr, i);
}

/*
 * This is the main function which will use the
 * min heap to find the minimum range which covers
 * all row's element
 */

void find_min_range(int mat[ROW][COL])
{
heap *arr = create_heap(ROW);
int i, j, max = INT_MIN, min = INT_MAX, range = INT_MAX;
int start, end;

	for(i = 0 ; i < ROW ; ++i)
	{
		arr->h_arr[i].element = mat[i][0];
		arr->h_arr[i].row = i;
		arr->h_arr[i].col = 1;

		if(max < mat[i][0])
			max = mat[i][0];
	}

	build_min_heap(arr);

	while(1)
	{
		min = arr->h_arr[0].element;

		if(range > max - min - 1)
		{
			range = max - min - 1;
			start = min;
			end = max;
		}

		if(arr->h_arr[0].col < COL)
		{
			int j = arr->h_arr[0].col;
			arr->h_arr[0].element = mat[arr->h_arr[0].row][j];
			arr->h_arr[0].col += 1;

			if(max < mat[arr->h_arr[0].row][j])
				max = mat[arr->h_arr[0].row][j];
		}

		else
			break;

		min_heapify(arr, 0);
	}

	printf("smallest Range = %d to %d\n",start, end);
}

int main()
{
int arr[ROW][COL] = {{4, 7, 30},
		     {1, 2, 3},
		     {10, 20, 40}};

	find_min_range(arr);

	return EXIT_SUCCESS;
}
