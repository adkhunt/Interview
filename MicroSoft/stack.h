#ifndef stack
#define stack

#include<stdbool.h>

typedef struct Stack{
			int start,limit;
			struct node **arr;
} Stack;

Stack* create_stack(int size)
{
	Stack *ret = (Stack*) malloc(sizeof(Stack));

	ret->start = -1;
	ret->limit = size;
	ret->arr = (struct node**) malloc(sizeof(struct node*)*size);

	return ret;
}

void push(Stack *s,struct node *nodeTopush)
{
	if(s->start != s->limit)
	{
		s->arr[++s->start] = nodeTopush;
	}

	else{	
		printf("STACK IS FULL\n");
		return;
	}
}

struct node* pop(Stack *s)
{
	if(s->start != -1)
	{
		return s->arr[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY\n");
		return NULL;
	}
}

struct node* top(Stack *s)
{
	return s->arr[s->start];
}

bool isEmpty(Stack *s)
{
	return s->start == -1;
}

#endif
