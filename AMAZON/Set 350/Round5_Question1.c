#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define page int

/*
 * Program to implement the LRU (least recent cache)
 * using queue and hash
 */

/*
 * struct variable that hols the page to load and
 * two pointer which used to make double link list
 */

struct QUEUE_NODE{
			page page_number;
			struct QUEUE_NODE *next;
			struct QUEUE_NODE *pre;
};

/*
 * This structure make the queue utility which has
 * two pointer first and last pointer which can be 
 * observed by size and filled_page variable if queue
 * is full or empty
 */

struct QUEUE{
		int size;
		int filled_page;
		struct QUEUE_NODE *first, *last;
};

/* 
 * This is the hash variable which can use for 
 * pointing the page and keep track of page in 
 * queue
 */

struct HASH{
		int capacity;
		struct QUEUE_NODE* *arr;
};

typedef struct QUEUE_NODE queue_node;
typedef struct QUEUE queue;
typedef struct HASH hash;

/*
 * This function create the queue of size which is passed
 * as the parameter in the function
 */

queue* create_queue(int total_frame)
{
	queue *temp = (queue*) malloc(sizeof(queue));

	temp->size = total_frame;
	temp->filled_page = 0;
	temp->first = NULL;
	temp->last = NULL;

	return temp;
}

/*
 * This function return the new frame of node with
 * page number which we want to load
 */

queue_node* get_new_frame(page page_number)
{
	queue_node *temp = (queue_node*) malloc(sizeof(queue_node));

	temp->page_number = page_number;
	temp->next = NULL;
	temp->pre = NULL;

	return temp;
}

/*
 * This function return the hash which points to 
 * the page which are currently in the queue
 */

hash* create_hash(int capacity)
{
	hash *temp = (hash*) malloc(sizeof(hash));
	temp->capacity = capacity;
	temp->arr = (queue_node**) malloc(sizeof(queue_node*)*capacity);

int i;

	for(i = 0 ; i < capacity ; ++i)
		temp->arr[i] = NULL;

	return temp;
}

/*
 * This function check if the queue is empty
 * or not
 */

bool is_queue_empty(queue *q)
{
	return q->filled_page == 0;
}

/*
 * This function check if queue is full or not
 */

bool is_queue_full(queue *q)
{
	return q->size == q->filled_page;
}

/*
 * This function will check if page which we are
 * going to the load is present in the queue cache
 * or not
 */

bool is_page_present(hash *h, page page_to_load)
{
	return h->arr[page_to_load] != NULL;
}

/*
 * This function print the cache queue with pages
 */

void print_cache(queue *q)
{
queue_node *temp = q->first;

	while(temp)
	{
		printf("%d ",temp->page_number);
		temp = temp->next;
	}

	printf("\n");
}

/*
 * If queue is full than first we have to remove last 
 * page from the queue so this function will remove 
 * last page from the queue
 */

void dequeue(queue *q, hash *h, page page_to_load)
{
	queue_node *node = q->last;

	q->last = node->pre;
	q->last->next = NULL;
	--(q->filled_page);
	h->arr[node->page_number] = NULL;
	free(node);
	node = NULL;
}

/*
 * If page is not in the queue than we have to add
 * new page to the queue so this function add the new
 * page to the queue
 */

void enqueue(queue *q, hash *h, page page_to_load)
{
	queue_node *node = get_new_frame(page_to_load);
	node->next = q->first;

	if(q->filled_page == 0)
		q->last = node;

	if(q->first != NULL)
		q->first->pre = node;

	q->first = node;
	h->arr[page_to_load] = node;
	++(q->filled_page);
}

/*
 * This function adds the page to the queue
 */

void load_to_cache(queue *q, hash *h, page page_to_load)
{
	if(q->size == q->filled_page)
	{
		dequeue(q, h, page_to_load);
		
	}
		enqueue(q, h, page_to_load);
}

/*
 * This is the main function which insert the page
 * and remove the pages from the queue.
 */

void load_page(queue *q, hash *h, page page_to_load)
{
	if(h->arr[page_to_load] == NULL)
		load_to_cache(q, h, page_to_load);

	else if(q->first != h->arr[page_to_load])
	{
		queue_node *node = h->arr[page_to_load];

		node->pre->next = node->next;
		if(node->next != NULL)
			node->next->pre = node->pre;

		if(node == q->last)
		{
			q->last = q->last->pre;
			q->last->next = NULL;
		}

		node->next = q->first;
		node->next->pre = node;
		node->pre = NULL;

		q->first = node;
	}
}

int main()
{
queue *q = create_queue(5);
hash *h = create_hash(6);

	load_page(q, h, 1);
	load_page(q, h, 2);
	load_page(q, h, 3);
	load_page(q, h, 4);
	load_page(q, h, 2);
	load_page(q, h, 5);
	load_page(q, h, 3);
	load_page(q, h, 1);

	print_cache(q);

	return EXIT_SUCCESS;
}
