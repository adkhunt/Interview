#include<stdio.h>
#include<stdlib.h>

#define null NULL
#define exit_success 0

////////////////////////////////////////
//				      //
// Sort two array with different size //
//				      //
////////////////////////////////////////

void move_at_first(int n,int a[n])
{
int i = 0, j = 1;

	while(a[i] != -1)
		++i;

	j = i+1;

	while(j < n)
	{
		if(a[j] != -1)
		{
			a[i] = a[j];
			a[j] = -1;
			++i;
		}

		++j;
	}
}

void sort_again(int m,int n,int a[m],int b[n])
{
int i=n-m-1,j=m-1,index = n-1;

	move_at_first(n,b);

	while(i >= 0 && j >= 0)
	{
		if(a[j] == b[i])
		{
			b[index] = b[i];
			--index;
			b[index] = a[j];
			--i,--j;
		}		

		else if(b[i] > a[j])
		{
			b[index] = b[i];
			--i;
		}

		else
		{
			b[index] = a[j];
			--j;
		}

		--index;
	}
}

int main()
{
int a[9] = {1,-1,-1,3,-1,4,-1,-1,5},i;
int b[5] = {1,2,3,4,5};

	sort_again(5,9,b,a);

	for(i = 0 ; i < 9 ; ++i)
		printf("%d ",a[i]);

	printf("\n");

	return exit_success;
}
