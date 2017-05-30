#include<stdio.h>
#define SUCCESS 0
#define N 5

/*
 * program to find the total number of island
 * made in matrix which filled with zero and 
 * one's
 */

/*
 * This function will return the zero or one
 * if the visited cell is not visited and also
 * check if the origin matrix have 0 or 1 in 
 * current cell
 */

int is_safe(int mat[][N], int row, int col, int visited[][N])
{
	 return (row >= 0 && col >= 0) &&
		(row < N && col < N) &&
		(mat[row][col] && !visited[row][col]) ;
}

/*
 * This function will check for neighbour in main
 * matrix if all neighbour are zero or one of 
 * current cell
 */

void check_neighbour(int mat[][N], int row, int col, int visited[][N])
{
	int row_neighbour[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int col_neighbour[] = {-1, -1, -1, 0, 0, 1, 1, 1};

	visited[row][col] = 1;
	int i;

	for(i = 0 ; i < 8 ; ++i)
	{
		if(is_safe(mat, row+row_neighbour[i], col+col_neighbour[i], visited))
			check_neighbour(mat, row+row_neighbour[i], col+col_neighbour[i], visited);
	}
}

/*
 * This is the main function which will count the
 * total number of island in the matrix
 */

int count_total_island(int mat[][N])
{
int i, j, count = 0;
int visited[N][N] = {0};

	for(i = 0 ; i < N ; ++i)
	{
		for(j =  0 ; j < N ; ++j)
		{
			if(is_safe(mat, i, j, visited))
			{
				check_neighbour(mat, i, j, visited);
				++count;
			}
		}
	}

	return count;
}

int main()
{
int mat[][N] = {{1, 1, 0, 1, 1},
		{0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}};

	int total_island = count_total_island(mat);

	printf("Total Number of island = %d\n",total_island);

	return SUCCESS;
}
