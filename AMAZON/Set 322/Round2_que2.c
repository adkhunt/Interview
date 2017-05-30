#include<stdio.h>
#include<stdlib.h>

#define exit_success 0

////////////////////////////////////
//				  //
// Program to reach at nth stairs //
//				  //
////////////////////////////////////

int find_steps(int stairs)
{
	if(stairs <= 2)
		return stairs;

int pre = 0,next,i,cur = 1;

	for(i = 0 ; i < stairs ; ++i)
	{
		next = cur + pre;
		pre = cur;
		cur = next;
	}

	return cur;
}

int main()
{
int n;

	printf("Enter number of stairs.\n");
	scanf("%d",&n);

	int steps = find_steps(n);

	printf("Minimum steps = %d\n",steps);

	return exit_success;
}
