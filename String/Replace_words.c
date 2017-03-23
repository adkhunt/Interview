#include<stdio.h>
#include<stdbool.h>
#include"string.h"

#define exit_success 0		// define the macro to 0 as exit_success

/** 
 * Program to replace the first string characters
 * With the second string character which are not 
 * Present in the both string
 */

/**
 * This function will replace the character of first
 * String which is not present in the second string
 */

void Replace_character(char *str1,char *str2)
{
/* Take the 26 size of bool array
 * to store the character of second string
 * as a hash table format
 */
bool arr[26] = {false};
int i;			// Iterator to travers the indexes

	for(i = 0 ; str2[i] ; ++i)
		arr[str2[i]-97] = true;		// Assume that all the characters are small in string

	for(i = 0 ; str1[i] ; ++i)
	{
		if(arr[str1[i]-97] == false)	// Replace the character if the character is not present
			str1[i] = '+';
	}
}

/*
 * Main program function
 */

int main()
{
char *str = NULL,*str2 = NULL;

	printf("Enter first string.\n");
	str = getString();		// Return the character pointer which is pointing to string

	printf("Enter second String.\n");
	str2 = getString();

	Replace_character(str,str2);

	printf("First String = %s\n",str);

	return exit_success;
}
