#include<stdio.h>
#include"matrix.h"
#define exit 0

/////////////////////////////////////////////////
//					       //
// Program to get the sum in matrix of any box //
// in non changing matrix		       //
//					       //
/////////////////////////////////////////////////

typedef struct coordinate{
				int x,y;
} point;

int** BuildMatrix(int **mat,int size)
{
int **ret = allocate_2D(size+1,size+1);
int i,j;

	for(i = 0 ; i <= size ; ++i)
	{
		ret[i][0] = 0;
		ret[0][i] = 0;
	}

	for(i = 1 ; i <= size ; ++i)
	{
		ret[1][i] = mat[0][i-1] + ret[1][i-1];
		ret[i][1] = mat[i-1][0] + ret[i-1][1];
	}

	for(i = 2 ; i <= size ; ++i)
	{
		for(j = 2 ; j <= size ; ++j)
		{
			ret[i][j] = mat[i-1][j-1] - ret[i-1][j-1] + ret[i-1][j] + ret[i][j-1];
		}
	}

	return ret;
}

int findSum(int **arr,point p1,point p2)
{
	int sum = arr[p2.x][p2.y] - arr[p1.x - 1][p2.y] 
		  - arr[p2.x][p1.y -1] + arr[p1.x-1][p1.y-1];

	return sum;
}

int main()
{
int **mat = null;
int size;
point p1,p2;

	printf("Enter square matrix size.\n");
	scanf("%d",&size);

	mat = allocate_2D(size,size);
	fill_Matrix(mat,size,size);
	print_Matrix(mat,size,size);

	printf("Enter index to find sum in matrix.\n");
	scanf("%d%d%d%d",&(p1.x),&(p1.y),&(p2.x),&(p2.y));

	int **res = BuildMatrix(mat,size);

	int sum = findSum(res,p1,p2);
	printf("Sum = %d\n",sum);

	return exit;
}
