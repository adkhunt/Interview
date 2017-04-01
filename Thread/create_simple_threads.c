#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

////////////////////////////////////////////////////////
//						      //
// Program to create a simple thread using pthread    //
//						      //
//////////////////////////////////////////////////////////
//						        //
// Note: While compiling code don't forget to link with //
// -pthread					        //
//						        //
//////////////////////////////////////////////////////////

void* thread_1(void *data)
{
char *str = (char*) data;
int i = 0;

	printf("%s\n",str);
	while(1);
}

void* thread_2(void *data)
{
char *str = (char*) data;
int i = 0;

	printf("%s\n",str);
}

int main()
{
pthread_t t1,t2;

	pthread_create(&t1,NULL,thread_1,"In thread 1");
	pthread_create(&t2,NULL,thread_2,"In thread 2");

	printf("In main function.\n");
	
	pthread_exit(0);

	return 0;
}
