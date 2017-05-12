#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 4

/*
 * Program to solve the question in which
 * 2D array is filled with 0s and 1s so
 * you can move if index is 1 else you can not
 * so from (0, 0) to reach at the (N-1, N-1)
 * find the path 
 */

/*
 * This function print the solution which we 
 * have solved
 */

void print_solution(int **sol)
{
int i,j;

	for(i = 0 ; i < SIZE ; ++i)
	{
		for(j = 0 ; j < SIZE ; ++j)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
}

/*
 * This function is to check if we can make
 * move to the current index or not
 */

bool is_safe(int mat[SIZE][SIZE], int row, int col)
{
	if((row >= 0 && row < SIZE) && (col >= 0 && col < SIZE)
		&& mat[row][col] == 1)
		return true;

	return false;
}

/*
 * Solve the problem using recursion and
 * using backtracking
 */

bool rat_in_maze(int mat[SIZE][SIZE], int row, int col, int **sol)
{
	if(row == SIZE-1 && col == SIZE-1)
	{
		sol[row][col] = 1;
		return true;
	}

	if(is_safe(mat, row, col))
	{
		sol[row][col] = 1;

		if(rat_in_maze(mat, row+1, col, sol))
			return true;

		if(rat_in_maze(mat, row, col+1, sol))
			return true;

		sol[row][col] = 0;
		return false;
	}

	return false;
}

int main()
{
int arr[SIZE][SIZE] = { {1, 0, 0, 0},
			{1, 1, 0, 1},
			{0, 1, 0, 0},
			{1, 1, 1, 1}};

int **solution = NULL;
int i;

	solution = (int**) malloc(sizeof(int*)*SIZE);

	for(i = 0 ; i < SIZE ; ++i)
		solution[i] = (int*) malloc(sizeof(int)*SIZE);

	if(rat_in_maze(arr, 0, 0, solution))
		print_solution(solution);

	else
		printf("No solution available.\n");


	return EXIT_SUCCESS;
}
