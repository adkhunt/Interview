#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define exit 0

///////////////////////////////////////////////////
//						 //
// Count the bit difference in all pair of array //
// element in O(n) time and also O(n2) time	 //
//						 //
///////////////////////////////////////////////////

int countSetBit(int num1,int num2)		// Return the bit difference of two number
{
int ret = 0,i,temp;

	temp = num1^num2;

	while(temp)
	{
		temp = temp & (temp-1);
		++ret;
	}

	return ret;
}

int getPair(int *a,int size)			// Count the set bit in O(n2) time 
{
int i,j,sum = 0;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = 0 ; j < size ; ++j)
		{
			sum += countSetBit(a[i],a[j]);
		}
	}

	return sum;
}

int Get_Count_Difference(int *a,int size)	// Count the bit difference in O(n) time
{
int i,ret = 0,j;

	for(i = 0 ; i < 32 ; ++i)
	{
		int count = 0;

		for(j = 0 ; j < size ; ++j)
		{
			if((a[j] >> i) & 1)
				++count;
		}

		ret += (count*(size-count)*2);
	}

	return ret;
}

int main()
{
int *a = null,size,i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	a = (int*) malloc(sizeof(int)*size);

	for(i = 0 ; i < size ; ++i)
		scanf("%d",&a[i]);

	int res = getPair(a,size);			// Count the bit difference in O(n2) Time
	printf("Difference is = %d\n",res);
	int ret = Get_Count_Difference(a,size);
	printf("Difference in O(n) time = %d\n",ret);

	return exit;
}
