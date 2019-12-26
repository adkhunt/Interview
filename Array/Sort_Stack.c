#include<stdio.h>
#include"stackInt.h"
#define exit 0

/////////////////////////////////////////////
//					   //
// Program to sort the stack without using //
// Extra memory				   //
//					   //
/////////////////////////////////////////////

void Insert(stack *s,int num)
{
	if(isEmpty(s) || (top(s) < num))
	{
		push(s,num);
		return;
	}

	int temp = pop(s);

	Insert(s,num);
	push(s,temp);	
}

void Sort_Stack(stack *s)
{
	if(isEmpty(s))
		return;

	int temp = pop(s);
	Sort_Stack(s);

	Insert(s,temp);
}

void print_stack(stack *s)
{
int i;

	for(i = s->start ; i >= 0 ; --i)
	{
		printf("| %d |\n",s->arr[i]);
		printf("----- \n");
	}
	printf("\n");
}

int main()
{
stack *s = create_stack(5);

	push(s,3);
	push(s,2);
	push(s,4);
	push(s,1);
	push(s,5);

	print_stack(s);
	Sort_Stack(s);
	printf("\n=================================\n");
	print_stack(s);


	return exit;
}
