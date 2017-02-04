#ifndef headerArray
#define headerArray

#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define exit 0

int* getArray(int size)
{
int *ret = (int*) malloc(sizeof(int)*size);

	return ret;
}

void fillArray(int *a,int size)
{
int i;

	printf("Enter array element.\n");

	for(i = 0 ; i < size ; ++i)
	{
		scanf("%d",&a[i]);
	}
}

void fillRandom(int *a,int size,int limit)
{
int i;

	srand(getpid());

	for(i = 0 ; i < size ; ++i)
		a[i] = (rand()%limit) + 1;
}

void printArray(int *a,int size)
{
int i;

	for(i = 0 ; i < size ; ++i)
		printf("%d ",a[i]);
	printf("\n");
}

#endif
