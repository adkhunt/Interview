#ifndef matrix
#define matrix

#include<stdlib.h>
#define null NULL

int** allocate_2D(int row,int col)
{
int i;

	int **mat = (int**) malloc(sizeof(int*)*row);

	for(i = 0 ; i < row ; ++i)
		mat[i] = (int*) malloc(sizeof(int)*col);

	return mat;
}

void fill_Matrix(int **mat,int row,int col)
{
int i,j;

	for(i = 0 ; i < row ; ++i)
		for(j =  0 ; j < col ; ++j)
			scanf("%d",&mat[i][j]);
}

void print_Matrix(int **mat,int row,int col)
{
int i,j;

	for(i = 0 ; i < row ; ++i)
	{
		for(j = 0 ; j < col ; ++j)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}

#endif
