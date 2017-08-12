#include<stdio.h>
#include<stdlib.h>

/*
 * Program to synchronize producer and consumer thread
 * using mutex in both threads
 */

pthread_mutex_t m1, m2;

/*
 * This thread produce the number which consumer
 * is going to consume
 */

void* producer(void *p)
{
int count = 0;
int *i_ptr = (int*) p;

	while(count < 20)
	{
		pthread_mutex_lock(&m1);
		*i_ptr = ++count;
		printf("Producer = %d\n",count);
		pthread_mutex_unlock(&m2);
	}
}

/*
 * This thread going to consume the number which was produced 
 * by the producer thread
 */

void* consumer(void *p)
{
int i;
int *i_ptr = (int*) p;

	for(i = 0 ; i < 20 ; ++i)
	{
		pthread_mutex_lock(&m2);
		printf("Consumer = %d\n",*i_ptr);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}
}

int main()
{
pthread_t t1, t2;
int var;

	pthread_mutex_lock(&m2);

	pthread_create(&t1, NULL, producer, &var);
	pthread_create(&t2, NULL, consumer, &var);

	pthread_exit(0);

	return EXIT_SUCCESS;
}
