#ifndef MIN_HEAP
#define MIN_HEAP

/*
 * This header contain normal heap property
 * like build heap function, heapify the heap
 */

/*
 * This structure contain the element of
 * matrix and that element cordinate like
 * row and next coloumn
 */

typedef struct HEAP_NODE{
				int element;
				int cur_row,next_col;
} heap_node;

/*
 * This is the main heap node which contain 
 * the limit of the heap node and array of
 * heap_node which has all row element in that 
 * array
 */

typedef struct HEAP{
			int limit;
			heap_node *heap_array;
} heap;

/*
 * This function create the heap node with 
 * limit of passed in the function parameter
 */

heap* create_heap(int limit)
{
	heap *temp = (heap*) malloc(sizeof(heap));

	temp->limit = limit;
	temp->heap_array = (heap_node*) malloc(sizeof(heap_node)*limit);

	return temp;
}

/*
 * This function swap the two heap_nodes
 */ 

void swap(heap_node *a, heap_node *b)
{
	heap_node temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Heapify the heap array with getting the minimum
 * at the index zero
 */

void min_heapify(heap *arr, int parent)
{
	int left_child = (parent * 2) + 1;
	int right_child = (parent * 2) + 2;
	int min = parent;

	if(left_child < arr->limit && 
		arr->heap_array[left_child].element < arr->heap_array[min].element)
		min = left_child;

	if(right_child < arr->limit &&
		arr->heap_array[right_child].element < arr->heap_array[min].element)
		min = right_child;

	if(min != parent)
	{
		swap(&(arr->heap_array[min]) , &(arr->heap_array[parent]));
		min_heapify(arr, min);
	}
}

/*
 * This function will build the heap while
 * we first time fill the array
 */

void build_heap(heap *arr)
{
int i = (arr->limit - 1) / 2;

	for(i ; i >= 0 ; --i)
		min_heapify(arr, i);
}

#endif
