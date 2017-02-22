#include<stdio.h>
#include<pthread.h>
#define exit_success 0
#define null NULL

/////////////////////////////////////////////////////
//						   //
// Program to synchronization between three thread //
//						   //
/////////////////////////////////////////////////////

pthread_mutex_t m1,m2,m3;

void* thread_capital(void *p)
{
char ch;

	for(ch = 'A' ; ch <= 'Z' ; ++ch)
	{
		pthread_mutex_lock(&m1);
		printf("%c\t",ch);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m2);
	}
}

void* thread_small(void *p)
{
char ch;

	for(ch = 'a' ; ch <= 'z' ; ++ch)
	{
		pthread_mutex_lock(&m2);
		printf("%c\t",ch);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m3);
	}
}

void* thread_number(void *p)
{
int i;

	for(i = 1 ; i < 27 ; ++i)
	{
		pthread_mutex_lock(&m3);
		printf("%d\n",i);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}

}

int main()
{
pthread_t t1,t2,t3;

	pthread_create(&t1,null,thread_capital,null);
	pthread_create(&t2,null,thread_small,null);
	pthread_create(&t3,null,thread_number,null);

	pthread_mutex_lock(&m2);
	pthread_mutex_lock(&m3);
	pthread_exit(0);
	return exit_success;
}
