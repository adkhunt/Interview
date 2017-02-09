#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INT_MAX 65535
#define INT_MIN -65535
#define null NULL
#define exit 0

////////////////////////////////////////////////
//					      //
// Program to get minimum and maximum in O(1) //
// Time from the stack			      //
//					      //
////////////////////////////////////////////////

typedef struct data{
			int limit,start;
			int *arr,*min,*max;
} stack;

stack* create_stack(int size)
{
	stack *s = (stack*) malloc(sizeof(stack));

	s->limit = size;
	s->start = -1;
	s->arr = (int*) malloc(sizeof(int)*size);
	s->min = (int*) malloc(sizeof(int)*(size+1));
	s->max = (int*) malloc(sizeof(int)*(size+1));
	s->min[0] = INT_MAX;
	s->max[0] = INT_MIN;

	return s;
}

void push(stack *s,int num)
{
	if(s->start != (s->limit-1))
	{
		s->arr[++s->start] = num;
		if(s->min[s->start] > num)
			s->min[s->start+1] = num;

		else 
			s->min[s->start+1] = s->min[s->start];

		if(s->max[s->start] < num)
			s->max[s->start+1] = num;

		else
			s->max[s->start+1] = s->max[s->start];
	}

	else
	{
		printf("Stack Is Full.\n");
	}
}

int pop(stack *s)
{
	if(s->start != -1)
	{
		return s->arr[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY.\n");
		return -1;
	}
}

void printStack(stack *s)
{
int i;

	for(i = s->start ; i>=0 ; --i)
	{
		printf("| %d |\n",s->arr[i]);
		printf(" ____\n");
	}
}

int getMin(stack *s)
{
	return s->min[s->start+1];
}

int getMax(stack *s)
{	return s->max[s->start+1];
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

void performOperation(stack *s,int op)
{
int num;

	switch (op)
	{
		case 1:
			printf("Enter number to push : ");
			scanf("%d",&num);
			push(s,num);
			break;

		case 2:
			num = pop(s);
			printf("Poped Element is : %d\n",num);
			break;

		case 3:
			printStack(s);
			break;

		case 4:
			num = getMin(s);
			printf("Minimum = %d\n",num);
			break;

		case 5:
			num = getMax(s);
			printf("Maximum = %d\n",num);
			break;			
	}
}

int main()
{
stack *s = create_stack(9);
int op,num;

	while(1)
	{
		printf("1) push\n2) pop\n3) print\n4) getMin\n5) getMax\n6) Exit\n");
		scanf("%d",&op);

		if(op!=6)
			performOperation(s,op);
		else
			break;

		printf("\n===============================\n");
	}

	return exit;
}
