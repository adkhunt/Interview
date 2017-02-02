#include<stdio.h>
#include<stdlib.h>
#include"stackInt.h"
#define exit 0
#define null NULL

////////////////////////////////////////////////
//					      //
// Program to reverse the stack without using //
// Extra space				      //
//					      //
////////////////////////////////////////////////

void Insert(stack *s,int num)
{
	if(isEmpty(s))
	{
		push(s,num);
		return;
	}

	int temp = pop(s);
	Insert(s,num);
	push(s,temp);
}

void Reverse_stack(stack *s)
{
	if(isEmpty(s))
		return;

	int temp = pop(s);
	Reverse_stack(s);

	Insert(s,temp);
}

void printStack(stack *s)
{
int i;

	for(i = s->start ; i >= 0 ; --i)
	{
		printf("| %d |\n",s->arr[i]);
		printf(" ___\n");
	}

}

int main()
{
stack *s = create_stack(5);

	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	push(s,5);

	printStack(s);
	Reverse_stack(s);
	printf("\n========== Reversed Stack ===========\n");
	printStack(s);

	return exit;
}
