#include<stdio.h>
#include<stdlib.h>
#include"stackInt.h"
#define exit 0
#define SIZE 6

/////////////////////////////////////////////////
//					       //
// Program to count stock span problem in O(n) //
// time complexity			       //
//					       //
/////////////////////////////////////////////////

void calculate_span(int arr[])
{
stack *s = create_stack(SIZE);
int temp[SIZE],i;

	temp[0] = 1;
	push(s,0);

	for(i = 1 ; i < SIZE ; ++i)
	{
		while(!isEmpty(s) && arr[top(s)] < arr[i])
			pop(s);

		
		temp[i] = isEmpty(s) ? i+1 : i - top(s);
		push(s,i);
	}

	for(i = 0 ; i < SIZE ; ++i)
		printf("%d ",temp[i]);
	printf("\n");
}

int main()
{
int arr[SIZE],i;

	printf("Enter element in array.\n");
	for(i = 0 ; i < SIZE ; ++i)
		scanf("%d",&arr[i]);

	calculate_span(arr);

	return exit;
}
