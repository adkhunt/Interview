#ifndef queue
#define queue

#include<stdbool.h>

typedef struct Queue{
			int top,bottom,limit;
			struct node **arr;
} Queue;

Queue* create_queue(int size)
{
	Queue *ret = (Queue*) malloc(sizeof(Queue));

	ret->top = -1;
	ret->bottom = -1;
	ret->limit = size;
	ret->arr = (struct node**) malloc(sizeof(struct node*));

	return ret;
}

void enqueue(Queue *q,struct node *data)
{
	if((q->top-q->bottom) != q->limit)
	{
		q->arr[++q->top] = data;
	}

	else
	{
		printf("QUEUE IS FULL\n");
	}
}

struct node* dequeue(Queue *q)
{
	if(q->bottom != q->top)
	{
		return q->arr[++q->bottom];
	}

	else
	{
		printf("QUEUE IS EMPTY\n");
		return NULL;
	}
}

struct node* front(Queue *q)
{
	if(q->bottom != q->top)
	{
		return q->arr[q->bottom+1];
	}

	else
	{
		printf("QUEUE IS EMPTY\n");
		return NULL;
	}
}

bool isQueueEmpty(Queue *q)
{
	return q->bottom == q->top;
}

#endif
