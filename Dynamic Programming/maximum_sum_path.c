#include<stdio.h>
#define EXIT 0
#define SIZE 4

//////////////////////////////////////////////////
//						//
// Program to find the maximum sum in triangle  //
// from top to Bottom				//
//						//
//////////////////////////////////////////////////

int Find_Maximum_Sum(int tri[SIZE][SIZE])
{
int i,j;

	for(i = SIZE-2 ; i >= 0 ; --i)
	{
		for(j = 0 ; j <= i ; ++j)
		{
			if(tri[i+1][j] > tri[i+1][j+1])
				tri[i][j] += tri[i+1][j];

			else
				tri[i][j] += tri[i+1][j+1];
		}
	}

	return tri[0][0];
}

int main()
{
int tri[SIZE][SIZE] = { {8,0,0,0},
			{-4,4,0,0},
			{2,2,6,0},
			{1,1,1,1} };

	int res = Find_Maximum_Sum(tri);

	printf("Maximum Sum = %d\n",res);

	return EXIT;
}
