#include<stdio.h>
#include<stdlib.h>
#define SPACE 32

/*
 * String which contains lowercase English letters and spaces. 
 * It may contain multiple spaces. Get first letter of 
 * every word and return the result as a string. 
 * The result should not contain any space
 */

char* get_first_chars(char *str)
{
char *ret = (char*) malloc(sizeof(char));
int i = 0, j = 0;

	if(str[0] != ' ')
		ret[j++] = str[i++];

	for(i  ; str[i-1] ; ++i)
	{
		if(str[i] == SPACE && str[i+1] != SPACE)
		{
			ret = (char*) realloc(ret, sizeof(char)*(j+1));
			ret[j++] = str[i+1];
		}			
	}

	return ret;
}

int main()
{
char *str = "This     is C     code";

	char *first_chars = get_first_chars(str);

	printf("Final String = %s\n",first_chars);

	return EXIT_SUCCESS;
}
