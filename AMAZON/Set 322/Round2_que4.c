#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define exit_success 0

typedef struct node{
			int disk;
			char dest,source,temp;
} node;

typedef struct STACK{
			int start,limit;
			node *buff;
} stack;

stack* create_stack(int size)
{
	stack *s = (stack*) malloc(sizeof(stack));

	s->start = -1;
	s->limit = size;
	s->buff = (node*) malloc(sizeof(node)*size);

	return s;
}

void push(stack *s,node data)
{
	if(s->start < s->limit)
	{
		s->buff[++s->start] = data;
	}

	else
		printf("STACK IS FULL.\n");
}

node pop(stack *s)
{
	if(s->start != -1)
	{
		node data =  s->buff[s->start--];
		return data;
	}

	else
		printf("STACK IS EMPTY.\n");
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void solve_toh_iterative(int disk,char source,char aux,char dest)
{
int n = disk,m = disk,count = 0;
node temp;
stack *s = create_stack(20);

	while(1)
	{
		if(n == 0)
			break;
		temp.disk = n--;
		temp.temp = aux;
		temp.dest = dest;
		temp.source = source;
		swap(&aux,&dest);
		push(s,temp);
	}

	while(!isEmpty(s))
	{
		temp = pop(s);
	
		printf("move %d from %c to %c\n",temp.disk,temp.source,temp.dest);
		if(temp.disk == 3)
			printf("mode %d from %c to %c\n",temp.disk-2,temp.temp,temp.source);
			
		if(temp.disk > 1)
		{
			node dt;
			dt.disk = temp.disk-1;
			dt.source = temp.temp;
			dt.temp = temp.source;
			dt.dest = temp.dest;
			push(s,dt);
		}
	}
}

void solve_toh(int disk,char source,char temp,char dest)	// Recursive Solution
{
	if(disk == 0)
		return;

	solve_toh(disk-1,source,dest,temp);
	printf("Move %d disk from %c to %c\n",disk,source,dest);
	solve_toh(disk-1,temp,source,dest);
}

int main()
{
int disk;

	printf("Enter disk to solve the tower of hanoi.\n");
	scanf("%d",&disk);

	solve_toh(disk,'a','b','c');
	printf("\n===============================\n");
	solve_toh_iterative(disk,'a','b','c');

	return exit_success;
}
