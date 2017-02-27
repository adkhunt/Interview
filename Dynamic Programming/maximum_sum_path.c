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
int i,j = 0,sum = tri[0][0];

	for(i = 1 ; i < SIZE ; ++i)
	{
		if(tri[i][j] > tri[i][j+1])
			sum += tri[i][j];

		else{
			sum += tri[i][j+1];
			++j;
		}
	}

	return sum;
}

int main()
{
int tri[SIZE][SIZE] = { {3,0,0,0},
			{7,4,0,0},
			{2,4,6,0},
			{8,5,9,3} };

	int res = Find_Maximum_Sum(tri);

	printf("Maximum Sum = %d\n",res);

	return EXIT;
}
