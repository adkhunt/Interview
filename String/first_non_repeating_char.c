#include<stdio.h>
#define SUCCESS 0
#define INT_MAX 1<<30

/*
 * This program is to find the first non
 * Repeating character in string
 */

/*
 * This function will return the first non
 * repeating character in the string
 */

char first_repeating(char *str)
{
int table[26] = {0}, i, min = INT_MAX;

	for(i = 0 ; str[i] ; ++i)
	{
		if(table[str[i] - 'a'] > 0)
			table[str[i] - 'a'] = -1;

		if(table[str[i] - 'a'] == 0)
			table[str[i] - 'a'] = i+1;
	}

	for(i = 0 ; i < 26 ; ++i)
	{
		if(table[i] > 0 && table[i] < min)
			min = table[i];
	}

	return str[min-1];
}

int main()
{
char str[20];

	printf("Enter string to get first non repeating char.\n");
	scanf("%s",str);

	char res = first_repeating(str);

	printf("First non-repeating character -> %c.\n",res);

	return SUCCESS;
}
