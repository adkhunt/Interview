#include<stdio.h>
#include<stdlib.h>

#define exit 0
#define null NULL

//////////////////////////////////////////////
//					    //
// Find a missing number from 1 to n stored //
// in array in non-sorted manner 	    //
//					    //
//////////////////////////////////////////////

int* allocate_in_heap(int size)
{
int *arr = (int*) malloc(sizeof(int)*size);

	return arr;
}

void scan_array(int *a,int size)
{
int i;

	for(i = 0 ; i < size ; ++i)
		scanf("%d",&a[i]);
}

void print_array(int *a,int size)
{
int i;

	for(i = 0 ; i < size ; ++i)
		printf("%d ",a[i]);

	printf("\n");
}

int find_missing(int *a,int size)
{
int i,sum = 0;

	for(i = 0 ; i < size ; ++i)
		sum += a[i];

	++size;

	int n = (size*(size+1))/2;

	return (n-sum);
}

int main()
{
int *arr = null,size;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	arr = allocate_in_heap(size);
	scan_array(arr,size);
	print_array(arr,size);

	int num = find_missing(arr,size);

	printf("missing num = %d\n",num);

	return exit;
}
