#include"headerArray.h"
#include<stdbool.h>

///////////////////////////////////////////
//					 //
// Count the distinct numbers from array //
// in O(n) time 			 //
//					 //
///////////////////////////////////////////

int getMax(int *a,int size)
{
int i,max = 0;

	for(i = 0 ; i < size ; ++i)
		if(max < a[i])
			max = a[i];

	return max;
}

int count_distinct(int *a,int size)
{
int i,count = 0;

	int max = getMax(a,size);

bool hash[max+1];

	for(i = 0 ; i <= max ; ++i)
		hash[i] = false;

	for(i = 0 ; i < size ; ++i)
		hash[a[i]] = true;

	for(i = 0 ; i <= max ; ++i)
		if(hash[i] == true)
			++count;

	return count;
}

int main()
{
int *a = null,size;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	a = getArray(size);
	fillArray(a,size);

	int res = count_distinct(a,size);

	printf("Total = %d\n",res);
	return exit;
}
