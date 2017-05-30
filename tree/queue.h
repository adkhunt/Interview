#ifndef queue
#define queue

#include<stdbool.h>

typedef struct QUEUE_NODE{
				struct node *data;
				struct QUEUE_NODE *next;
				struct QUEUE_NODE *pre;
} queue_node;

typedef struct Queue{
			int filled,limit;
			queue_node *front, *back;
} Queue;

Queue* create_queue(int size)
{
	Queue *temp = (Queue*) malloc(sizeof(Queue));

	temp->limit = size;
	temp->filled = 0;
	temp->front = NULL;
	temp->back = NULL;

	return temp;
}

queue_node* get_new_node(struct node *data)
{
	queue_node *temp = (queue_node*) malloc(sizeof(queue_node));

	temp->data = data;
	temp->next = NULL;
	temp->pre = NULL;

	return temp;
}

void enqueue(Queue *q, struct node *data)
{
	queue_node *cur_node = get_new_node(data);

	if(q->filled == q->limit)
	{
		printf("Queue is full.\n");
		return ;
	}

	else if(q->filled > 0)
	{
		cur_node->next = q->front;
		q->front->pre = cur_node;
		q->front = cur_node;
	}

	else
	{
		q->front = cur_node;
		q->back = cur_node;
	}

	++(q->filled);
}

struct node* dequeue(Queue *q)
{
	if(q->filled <= 0)
	{
		printf("Queue is empty.\n");
		return NULL;
	}

	else if(q->filled > 1)
	{
		queue_node *temp_node = q->back;
		struct node *ret = temp_node->data;
		q->back = temp_node->pre;
		free(temp_node);
		temp_node = NULL;
		--(q->filled);
		return ret;
	}

	else
	{
		struct node *ret = q->back->data;
		free(q->back);
		q->back = q->front = NULL;
		--(q->filled);
		return ret;
	}
}

struct node* front(Queue *q)
{
	if(q->filled <= 0)
	{
		printf("Queue is empty.\n");
		return NULL;
	}

	else
	{
		return q->back->data;
	}
}

bool isQueueEmpty(Queue *q)
{
	return q->filled == 0;
}

#endif
