#include<stdio.h>
#include"stack.h"

/* This program is to create a queue using 
 * the single stack
 */

/*
 * This function will return the last element in the
 * stack which is the first entered into this stack 
 */

int dequeue(stack *s)
{
	int temp = pop(s);

	if(is_empty(s))
		return temp;

	int res = dequeue(s);
	push(s,temp);

	return res;
}

/*
 * This is the main function which handle 
 * all task
 */

int main()
{
stack *s = create_stack(5);

	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	push(s,5);

	int res = dequeue(s);
	printf("Result = %d\n",res);

	res = dequeue(s);
	printf("Result = %d\n",res);
	
	res = dequeue(s);
	printf("Result = %d\n",res);
	
	res = dequeue(s);
	printf("Result = %d\n",res);

	return EXIT_SUCCESS;
}
