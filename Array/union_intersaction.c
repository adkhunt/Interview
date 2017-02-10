#include<stdio.h>
#include<stdlib.h>
#include"headerArray.h"
#include<stdbool.h>

#define exit 0
#define null NULL

///////////////////////////////////////////////////
//						 //
// Print the union and interaction of two arrays //
//						 //
///////////////////////////////////////////////////

int getMax(int *a,int size)
{
int i,max = 0;

	for(i = 0 ; i < size ; ++i)
		max = a[i] > max ? a[i] : max;

	return max;
}

void print_interaction(int *a,int *b,int size)
{
int max = getMax(a,size),i;
int max2 = getMax(b,size);
max = max > max2 ? max : max2;
int hash[max+1];

	for(i = 0 ; i <= max ; ++i)
		hash[i] = 0;

	for(i = 0 ; i < size ; ++i)
	{
		++hash[a[i]];
		++hash[b[i]];
	}

	for(i = 0 ; i <= max ; ++i)
		if(hash[i] >1)
			printf("%d ",i);

	printf("\n");
}

void print_union(int *a,int *b,int size)
{
int max = getMax(a,size),i;
int max2 = getMax(b,size);
max = max > max2 ? max : max2;
bool hash[max+1];

	for(i = 0 ; i <= max ; ++i)
		hash[i] = false;

	for(i = 0 ; i < size ; ++i)
	{
		hash[a[i]] = true;
		hash[b[i]] = true;
	}

	for(i = 0 ; i <= max ; ++i)
		if(hash[i])
			printf("%d ",i);

	printf("\n");
}

int main()
{
int *a = null,*b = null;
int size;

	printf("Enter size of array.\n");
	scanf("%d",&size);
	a = getArray(size);
	b = getArray(size);

	printf("Enter element in first array.\n");
	fillArray(a,size);
	printf("Enter element in second array.\n");
	fillArray(b,size);

	print_union(a,b,size);
	print_interaction(a,b,size);

	return exit;
}
