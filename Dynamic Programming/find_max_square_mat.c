#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"
#define exit 0
#define null NULL

//////////////////////////////////////////
//					//
// To find biggest square pixel made up //
// From 1s in matrix contain with 0 and //
// one's				//
//					//
//////////////////////////////////////////

int min(int a,int b,int c)
{
	return a < b ? a < c ? a : c : b < c ? b : c;
}

int max(int a,int b)
{
	return a > b ? a : b;
}

void countSquareMatrix(int **mat,int size)
{
int temp[size][size];
int i,j,maximum = 0;

	for(i = 0 ; i < size ; ++i)
	{
		temp[i][0] = 0;
		temp[0][i] = 0;
	}

	for(i = 1 ; i < size ; ++i)
	{
		for(j = 1 ; j < size ; ++j)
		{
			if(mat[i][j] == 1)
				temp[i][j] = min(temp[i-1][j],temp[i][j-1],temp[i-1][j-1])+1;

			else
				temp[i][j] = 0;
		}
	}

	for(i = 0 ; i < size ; ++i)
	{
		for(j = 0 ; j < size ; ++j)
			maximum = max(maximum,temp[i][j]);
	}

	printf("max = %d\n",maximum);

}

int main()
{
int size;

	printf("Enter size of squre matrix.\n");
	scanf("%d",&size);

	int **mat = allocate_2D(size,size);
	printf("Enter elements in matrix.\n");
	fill_Matrix(mat,size,size);
	print_Matrix(mat,size,size);

	countSquareMatrix(mat,size);

	return exit;
}
