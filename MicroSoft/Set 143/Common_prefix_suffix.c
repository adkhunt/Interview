#include<stdio.h>

/*
 * Program to print the longest suffix which is
 * present in the main string
 */

/*
 * This function print the longest suffix which is
 * present in the main string
 */

void find_longest_string(char *main_string, char *pattern)
{
int i = 0, j = 0;

	while(1)
	{
		if(main_string[i] == 0 || pattern[j] == 0)
			break;

		if(main_string[i] == pattern[j])
			++j;

		++i;
	}

	for(i = 0 ; i < j ; ++i)
		printf("%c",pattern[i]);

	printf("\n");
}

int main()
{
char *pattern = "digger";
char *main_string = "biggerdiagram";

	find_longest_string(main_string, pattern);

	return SUCCESS;
}
