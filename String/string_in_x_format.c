#include<stdio.h>
#define SUCCESS 0

/*
 * Program to print the string in the 'X'
 * format like
 * str = "12345"

	1   5
    	 2 4
	  3
	 2 4
	1   5 
 */

/*
 * Return the lenght of the string
 */

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

/*
 * Print in passed string in the 'X' 
 * format
 */

void print_x_format(char *str)
{
int len = my_strlen(str);
int i, j;

	for(i = 0 ; str[i] ; ++i)
	{
		for(j = 0 ; str[j] ; ++j)
		{
			if(j == i || j == (len - 1 - i))
				printf("%c",str[j]);
			else
				printf(" ");
		}

		printf("\n");
	}
}

int main()
{
char str[20];

	printf("Enter string.\n");
	scanf("%s",str);

	print_x_format(str);

	return SUCCESS;
}
