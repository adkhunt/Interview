#ifndef STACK_HEADER
#define STACK_HEADER

#include<stdlib.h>

struct STACK_NODE{
			int limit;
			int cur_index;
			char *arr;
};

typedef struct STACK_NODE stack;

stack* create_stack(int size)
{
	stack *temp = (stack*) malloc(sizeof(stack));

	temp->limit = size;
	temp->cur_index = -1;
	temp->arr = (char*) malloc(sizeof(char)*size);

	return temp;
}

void push(stack *s, char data)
{
	if(s->cur_index < s->limit)
		s->arr[++s->cur_index] = data;

	else
		printf("STACK IS FULL.\n");
}

char pop(stack *s)
{
	if(s->cur_index >= 0)
		return s->arr[s->cur_index--];

	else
		printf("STACK IS EMPTY.\n");
}

char top(stack *s)
{
	if(s->cur_index >= 0)
		return s->arr[s->cur_index];

	else
		return '$';
}

int is_empty(stack *s)
{
	return s->cur_index == -1;
}

#endif
