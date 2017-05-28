#include<stdio.h>
#define SUCCESS 0
#define INT_MAX 1<<30

int min(int a, int b)
{
	return a < b ? a : b;
}

int get_min_path(int index, int req,int step)
{
	if(index < step)
		return INT_MAX;

	if(index == step)
		return step;

	int pos = get_min_path(index ,index+step, step+1);
	int neg = get_min_path(index ,index-step, step+1);

	return min(pos, neg);
}

int main()
{
int step = 15;

	int res = get_min_path(11, 0, 0);

	printf("res = %d\n",res);


	return SUCCESS;
}
