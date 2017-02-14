#include<stdio.h>

#define exit 0
#define ROW 4
#define COL 5
#define null NULL

///////////////////////////////////////
//				     //
// Program to generate sparse matrix //
//				     //
///////////////////////////////////////

/* Sparse matrix is matrix which most of element
   Are zero */

void generate_sparse(int row,int col,int mat[row][col])
{
int i,j,count = 0;

	for(i = 0 ; i < row ; ++i)
		for(j = 0 ; j < col ; ++j)
			if(mat[i][j] != 0)
				++count;

int temp[3][count],index = 0;

	for(i = 0 ; i < row ; ++i)
	{
		for(j = 0 ; j < col ; ++j)
		{
			if(mat[i][j] != 0)
			{
				temp[0][index] = i;
				temp[1][index] = j;
				temp[2][index] = mat[i][j];
				++index;
			}
		}
	}

	for(i = 0 ; i < 3 ; ++i)
	{
		for(j = 0 ; j < count ; ++j)
			printf("%d ",temp[i][j]);
		printf("\n");
	}
}

int main()
{
int matrix[ROW][COL],i,j,count=0;

	printf("Enter element in 4*4 matrix.\n");
	for(i = 0 ; i < ROW ; ++i)
		for(j = 0 ; j < COL ; ++j)
			scanf("%d",&matrix[i][j]);

	generate_sparse(ROW,COL,matrix);

	return exit;
}
