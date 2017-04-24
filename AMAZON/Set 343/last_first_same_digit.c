#include<stdio.h>
#include<stdbool.h>

int is_same_digit(int num)
{
int last,first;

	last = num % 10;

	while(num)
	{
		first = num;
		num = num/10;
	}

	return last == first;
}

void print_number(int start, int end)
{
int i;

	for(i = start ; i < 10 ; ++i)
		printf("%d ",i);

	for(i = 11 ; i < end ; ++i)
		if(is_same_digit(i))
			printf("%d ",i);

	printf("\n");
}

int main()
{
int start,end;

	printf("Enter start and end limit to print numbers.\n");
	scanf("%d%d",&start,&end);

	print_number(start,end);

	return 0;
}
