#include<stdio.h>
#define INT_MAX 1<<30

/*
 * Program to find the first non repeating character
 * in the stream of character
 */

/*
 * This function will find the first non repeating 
 * character in the string using the position of 
 * the character in the string using hashing
 */

int find_first_non_repeating(char *str)
{
int table[26] = {0};
int i;

	for(i = 0 ; str[i] ; ++i)
	{
		if(table[str[i] - 'a'] == 0)
			table[str[i] - 'a'] = i+1;

		else
			table[str[i] - 'a'] = -1;
	}

int min = INT_MAX;

	for(i = 0 ; i < 26 ; ++i)
	{
		if(min > table[i] && table[i] > 0)
			min = table[i];
	}

	return min-1;
}

int main()
{
char *str = "geeksforgeeks";

	int res = find_first_non_repeating(str);

	printf("first non repeating char = %c\n",str[res]);

	return 0;
}
