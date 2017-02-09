#include<stdio.h>
#include<stdlib.h>
#include"headerArray.h"
#include"sort.h"
#define exit 0
#define null NULL

/////////////////////////////////////////////////////
//						   //
// Program to find the pythagoras triplet in array //
//						   //
/////////////////////////////////////////////////////

void find_triplet(int *a,int size)
{
int i,j,k,sum;

	for(i = 0 ; i < size ; ++i)
		a[i] *=  a[i];

	quickSort(a,0,size-1);

	for(i = size-1 ; i >= 0 ; --i)
	{
		j = 0,k = i-1;

		while(j < k)
		{
			sum = a[j] + a[k];
			
			if(sum == a[i])
			{
				printf("%d + %d = %d\n",a[j],a[k],a[i]);
			}

			sum > a[i] ? --k : ++j;
		}
	}
}

int main()
{
int *a = null;
int size,i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	a = getArray(size);
	fillArray(a,size);	

	find_triplet(a,size);

	return exit;
}
