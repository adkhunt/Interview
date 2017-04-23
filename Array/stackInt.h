#ifndef STACKINT
#define STACKINT

#include<stdbool.h>
#include<stdlib.h>

typedef struct data{
			int start,limit;
			int *arr;
} stack;

stack* create_stack(int size)
{
	stack *s = (stack*)
			malloc(sizeof(stack));

	s->start = -1;
	s->limit = size;
	s->arr = (int*) malloc(sizeof(int)*size);

	return s;
}

void push(stack *s,int num)
{
	if(s->start != s->limit-1)
	{
		s->arr[++s->start] = num;
	}

	else
	{
		printf("STACK IS FULL.\n");
		return;
	}
}

int pop(stack *s)
{
	if(s->start >= 0)
	{
		return s->arr[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY.\n");
		return -1;
	}
}

int top(stack *s)
{
	return s->arr[s->start];
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

#endif
