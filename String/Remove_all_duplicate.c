#include<stdio.h>
#include<stdbool.h>
#define SUCCESS 0

/*
 * Program to remove duplicate from the string
 * in O(n) time.
 */

/*
 * Return the length of the string which passed
 * in the parameter
 */

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

/*
 * This function will remove the duplicate character
 * in O(n) time
 */

void Remove_duplicate(char *str)
{
int len = my_strlen(str);
int count = 0, i;
bool table[26] = {false};

	for(i = 0 ; i + count <= len ; ++i)
	{
		if(table[str[i] - 'a'] == false)
		{
			str[i-count] = str[i];
			table[str[i] - 'a'] = true;
		}

		else
			++count;
	}

	str[i-count] = '\0';
}

int main()
{
char str[20];

	printf("Enter string.\n");
	scanf("%s",str);

	Remove_duplicate(str);

	printf("New string = %s\n",str);

	return SUCCESS;
}
