#include<stdio.h>
#include<stdlib.h>

/*
 * Program to multiply two numbers stored in 
 * single linklist
 */

/*
 * Structure variable which have integer 
 * field and one self referencial structure
 */

struct node{
		int num;
		struct node *next;
};

/*
 * Return the node with number initialised
 * and next pointer to null
 */

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

/*
 * Add new node at the end of the list
 */

void add_node(struct node **hptr,int num)
{
static struct node *pre = NULL;

	if(*hptr != NULL)
	{
		pre->next = get_new_node(num);
		pre = pre->next;
	}

	else
	{	
		*hptr = get_new_node(num);
		pre = *hptr;
	}
}

/*
 * Print the linked list 
 */

void print_list(struct node *hptr)
{
	while(hptr != NULL)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

/*
 * Reverse the linklist recursively
 */

struct node* reverse_list(struct node *hptr)
{
	if(hptr == NULL || hptr->next == NULL)
		return hptr;

	struct node *temp = reverse_list(hptr->next);

	hptr->next->next = hptr;
	hptr->next = NULL;

	return temp;
}

/*
 * This is the main function which will do 
 * multilication of two large number which are stored
 * into the linked-list
 */

void perform_operation(struct node *num1, struct node *num2, struct node *res)
{
int mul = 0, digit = 0, carry = 0;

	while(num1 != NULL)
	{
		/*
		 * Make the multiplication of the two numbers
		 * with current node and with addition of carry
		 */

		mul  = ((num1->num) * (num2->num)) + carry + res->num; 

		/*
		 * Extract two digit if number is greater than 9
		 */
		digit = mul % 10;
		carry = mul/10;

		/*
		 * insert the digit into the result node
		 */

		res->num = digit;

		/*
		 * If res->next node is null than it will get
		 * new node with 0 initialise.
		 */

		if(res->next == NULL)
		{
			res->next = get_new_node(0);
		}

		res = res->next;
		num1 = num1->next;
	}

	/*
	 * If last number have multiplication greater than 9 
	 * than we have to add that number into the last node
	 */

	if(carry != 0)
	{
		res->num = res->num + carry;
	}
}

struct node* multiply(struct node *num1,struct node *num2)
{
	if(num1 == NULL || num2 == NULL)
	{
		printf("Number should not empty.\n");
		return NULL;
	}

struct node *res = get_new_node(0);
struct node *temp = res;

	num1 = reverse_list(num1);	// Reverse the linklist to
	num2 = reverse_list(num2);	// Make process easy

	while(num2 != NULL)
	{
		perform_operation(num1, num2, temp);
		num2 = num2 -> next;
		temp = temp->next;
	}

	res = reverse_list(res);	// Reversr the result list

	/*
	 * Remove the extra front node with zero.
	 * if result is zero than we have to check
	 * for that also
	 */

	while(res->num == 0 && res->next != NULL)		
	{
		temp = res->next;
		free(res);
		res = temp;
	}

	return res;
}

int main()
{
struct node *num1 = NULL, *num2 = NULL;
char str[20];
int i;

	printf("Enter two long number to multiply.\n");
	scanf("%s",str);

	for(i = 0 ; str[i] ; ++i)
		add_node(&num1,str[i]-48);

	scanf("%s",str);

	for(i = 0 ; str[i] ; ++i)
		add_node(&num2,str[i]-48);

	struct node *res = multiply(num1,num2);

	print_list(res);

	return EXIT_SUCCESS;
}
