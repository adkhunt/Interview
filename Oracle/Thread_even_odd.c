#include<stdio.h>
#include<pthread.h>

/*
 * Program to print even and odd from two
 * different thread
 */


/*
 * create two pthread_mutex variable to
 * synchronise two threads
 */

pthread_mutex_t m1, m2;

/*
 * Print odd numbers in the thread
 */

void* print_odd(void *p)
{
int i;
int *int_ptr = (int*) p;
int limit = *int_ptr;

	for(i = 1 ; i <= limit  ; i += 2)
	{
		pthread_mutex_lock(&m1);
		printf("%d ",i);
		pthread_mutex_unlock(&m2);
	}

	printf("\n");
}

/*
 * Print even number in the thread
 */

void* print_even(void *p)
{
int i;
int *int_ptr = (int*) p;
int limit = *int_ptr;

	for(i = 2 ; i <= limit ; i += 2)
	{
		pthread_mutex_lock(&m2);
		printf("%d ",i);
		pthread_mutex_unlock(&m1);
	}

	printf("\n");
}

int main()
{
pthread_t t1, t2;
int limit;

	printf("Enter limit to print number.\n");
	scanf("%d",&limit);

	pthread_create(&t1, NULL, print_odd, &limit);
	pthread_create(&t2, NULL, print_even, &limit);

	pthread_mutex_lock(&m2);
	pthread_exit(0);
	return 0;
}
