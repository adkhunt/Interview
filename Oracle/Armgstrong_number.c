#include<stdio.h>

/*
 * Program to get the armstrong number from
 * 1 to n
 */

/*
 * This function will check the if number
 * is prime or not
 */

int is_armstrong(int num)
{
int res = 0, rem, temp = num;

	while(num)
	{
		rem = num % 10;
		res += (rem*rem*rem);
		num = num/10;
	}

	return temp == res;
}

/*
 * this function will check for number from 1 
 * to n
 */

void print_armstrong(int n)
{
int i;

	for(i = 1 ; i < n ; ++i)
	{
		if(is_armstrong(i))
			printf("%d ",i);
	}

	printf("\n");
}

int main()
{
int n;

	printf("Enter n to print all armstrong numbers.\n");
	scanf("%d",&n);

	print_armstrong(n);

	return 0;
}
