#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

//////////////////////////////////////////////
//					    //
// Program to get the row which has maximum //
// Number of one's			    //
//					    //
//////////////////////////////////////////////

int getMaxRow(int **mat,int row,int col)
{
int i = 0,j = --col , max = 0;

	while(i < row && j >= 0)
	{
		if(mat[i][j] == 1)
		{
			--j;
			max = i;
		}

		else
			++i;
	}

	return max;
}

int main()
{
int **mat = null,row,col;
int i,j;

	printf("Enter size of row and coloum of matrix.\n");
	scanf("%d%d",&row,&col);

	mat = (int**) malloc(sizeof(int*)*row);
	for(i = 0 ; i < row ; ++i)
		mat[i] = (int*) malloc(sizeof(int)*col);

	printf("Enter element in matrix.\n");		// Enter only sorted 0 and 1 in matrix
	for(i = 0 ; i < row ; ++i)
		for(j = 0 ; j < col ; ++j)
			scanf("%d",&mat[i][j]);

	int row_max_one = getMaxRow(mat,row,col);

	printf("Maximum one in row = %d\n",row_max_one);

	return exit;
}
