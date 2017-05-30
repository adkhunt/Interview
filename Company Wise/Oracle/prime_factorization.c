#include<stdio.h>

/*
 * Print prime factorization from 1 to n
 */ 

/*
 * This function will print the prime factorization
 * of number which is passed in parameter
 */

void print_prime_factorization(int n)
{
int i;

	if(n == 1)
	{
		printf("%d ",n);
		return;
	}

	while(n != 1)
	{
		for(i = 2 ; i <= n ; ++i)
		{
			if(n % i == 0)
			{
				printf("%d ",i);
				n = n/i;
				break;
			}
		}
	}
}

int main()
{
int n,i;

	printf("Enter n value to print prime factorization.\n");
	scanf("%d",&n);

	for(i = 1 ; i <= n ; ++i)
	{
		printf("%d -> ",i);
		print_prime_factorization(i);
		printf("\n");
	}

	return 0;
}
