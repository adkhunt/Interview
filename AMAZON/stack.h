#ifndef STACK
#define STACK

#include<stdlib.h>
#include<stdbool.h>

/*
 * This header file consist of some basic 
 * operation which we perform on the stack 
 * like push, pop, and is_empty
 */

/*
 * Struct variable which store the all stack
 * information and start and end limit
 */

typedef struct STACK{
			int *arr,start;
			int limit;
} stack;

/*
 * This function will create the stack and
 * return the pointer to the stack which is 
 * created.
 */

stack* create_stack(int limit)
{
	stack *s = (stack*) malloc(sizeof(stack));

	s->arr = (int*) malloc(sizeof(int)*limit);
	s->limit = limit-1;
	s->start = -1;

	return s;
}

/*
 * This function will push the data to the 
 * stack
 */

void push(stack *s,int data)
{
	if(s->start < s->limit)
	{
		s->arr[++s->start] = data;
	}

	else
	{	
		printf("STACK IS FULL.\n");
	}
}

/*
 * This function will pop the data and return 
 * to the caller function.
 */

int pop(stack *s)
{
	if(s->start > -1)
	{
		return s->arr[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY.\n");
		return -1;
	}
}

/*
 * This function will retuen the true
 * If the stack is emtpy.
 */

bool is_empty(stack *s)
{
	return s->start == -1;
}

#endif
