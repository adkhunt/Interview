#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//////////////////////////////////////////
//					//
// Sort stack without using extra space //
//					//
//////////////////////////////////////////

typedef struct STACK{
			int start,limit;
			int *arr;
} stack;

stack* create_stack(int size)
{
	stack *s = (stack*) malloc(sizeof(stack));

	s->start = -1;
	s->limit = size;
	s->arr = (int*) malloc(sizeof(int)*size);

	return s;
}

void push(stack *s,int num)
{
	if(s->start < s->limit)
	{
		s->arr[++s->start] = num;
	}

	else
		printf("\nSTACK IS FULL\n");
}

int pop(stack *s)
{
	if(s->start != -1)
	{
		return s->arr[s->start--];
	}

	else
		printf("\nSTACK IS EMPTY\n");
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

int top(stack *s)
{
	return s->arr[s->start];
}

void print_stack(stack *s)
{
int i;

	for(i = s->start ; i >= 0 ; --i)
	{
		printf("| %d |\n",s->arr[i]);
		printf("_____\n");
	}
}

void insert(stack *s,int num)
{
	if(isEmpty(s) || num >= top(s))
	{
		push(s,num);
		return;
	}

	int temp = pop(s);

	insert(s,num);
	push(s,temp);
}

void sort_stack(stack *s)
{
int temp;

	if(isEmpty(s))
		return;

	temp = pop(s);

	sort_stack(s);

	insert(s,temp);
}

int main()
{
stack *s = create_stack(5);

	push(s,1);
	push(s,5);
	push(s,2);
	push(s,4);
	push(s,3);

	print_stack(s);

	sort_stack(s);

	printf("\n======== Sorted Stack ========\n");

	print_stack(s);

	return EXIT_SUCCESS;
}
