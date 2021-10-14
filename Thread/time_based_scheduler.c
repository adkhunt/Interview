#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_THREAD 10

pthread_t MAX_JOB[MAX_THREAD];
int counter;

typedef struct job_detail{
	int timer;
	char *str;
} job_detail;

void* execute_job(void *args){
	job_detail *detail = (job_detail*) args;
	sleep(detail->timer);
	printf ("%s\n", detail->str);
}

void schedule_job(void* job (void*), int time, char *str){

	pthread_t t;
	job_detail *detail = (job_detail*) malloc(sizeof(job_detail));
	detail->timer = time;
	detail->str = str;
	pthread_create(&t, NULL, job, detail);
	MAX_JOB[counter++] = t;
}

int main(){

	schedule_job(execute_job, 6, "Hi");
	schedule_job(execute_job, 2, "Hello");
	sleep(3);
	schedule_job(execute_job, 4, "Bye");

	int i;
	for (i = 0 ; i < counter ; ++i){
		pthread_join(MAX_JOB[i], NULL);
	}

	return 0;
}
