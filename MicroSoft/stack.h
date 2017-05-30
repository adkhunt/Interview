#ifndef STACK
#define STACK

#include<stdbool.h>

/*
 * This header file contain the basic functionality
 * of the stack like push, pop and is stack empty
 * or not
 */

/*
 * This structure contain the start index and
 * limit of the stack and also void double pointer
 * which holds the pointer of linklist
 */

typedef struct STACK{
			int start,limit;
			void **p;
} stack;

/*
 * Create the stack of size passed in the 
 * parameter 
 */

stack* create_stack(int size)
{
	stack *ret = (stack*) malloc(sizeof(stack));

	ret->start = -1;
	ret->limit = size-1;
	ret->p = (void**) malloc(sizeof(void*) * size);

	return ret;	
}

/*
 * This is the push function which holds
 * the address of passed node in parameter
 */

void push(stack *s, void *data_to_push)
{
	if(s -> start < s->limit)
	{
		s->p[++s->start] = (void*) data_to_push;
	}

	else
	{
		printf("STACK IS FULL.\n");
	}
}

/*
 * This is the pop function which return the 
 * top node
 */

void* pop(stack *s)
{
	if(s -> start != -1)
	{
		return s->p[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY.\n");
		return NULL;
	}
}

/*
 * This function return true if the stack
 * is empty
 */

bool is_empty(stack *s)
{
	return s->start == -1;
}

#endif
