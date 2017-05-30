/* program to find the entered number is
 * prime number or not prime number if it 
 * is print "prime" else print "not prime"
 */

#include<stdio.h>

#define exit_success 0

/* This function is taking the number as parameter 
 * which we are going to check wether its prime or not
 * we iterate though all number from 2 to num-1 if 
 * in between that we get remainder 0 than we just return 
 * 0 because it shows that the given number is not prime
 * else if we completed for loop that means the given number
 * is prime number and we return 1
 */

int isPrime(int num)
{
/* Varible to iterate from 2 to num-1
 */
int i;

	for(i = 2 ; i < num ; ++i)
	{
		if(num % i == 0)
			return 0;	// if the module with number not give any remainder than it will return 1
	}

	return 1;
}

int main()
{
int num;

	/* prompt to use to enter number which
	 * which user is going to check
	 */

	printf("Enter number to check prime or not?\n");
	scanf("%d",&num);

	/* Call the function to check if number is
	 * prime or not if its prime than return 1
	 * else return 0
	 */

	if(isPrime(num))
		printf("%d is prime number.\n",num);

	else
		printf("%d is not prime.\n",num);


	/* return to parent process that 
	 * task completed successfully
	 */
	return exit_success;
}
