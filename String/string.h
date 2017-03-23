#ifndef string
#define string

#include<stdio.h>
#include<stdlib.h>
#define null NULL

/*
 * This function will scan the dynamic size of string
 * From the user and return the character pointer
 */

char* getString(void)
{
char *ret = null,ch;
int i = 0;

	/*
	 * Allocate the memory to charater pointer of size character
	 */

	ret = (char*) malloc(sizeof(char));

	/*
 	 * While loop will run untill '\n' not encountered
	 * and that scanned charater will store the dynamically
	 * allocated memory and resize the character pointer 
	 * Upto not pressed the 'Enter' Button
	 */

	while((ch=getc(stdin)) != '\n')
	{
		ret[i++] = ch;
		ret = realloc(ret,i+1);
	}

	/*
	 * At the end of the string we put '\0'
	 * To indicate that the string is terminating here
	 */
	ret[i] = '\0';

	/*
	 * Return the character pointer which is 
	 * Pointing to the string
	 */
	return ret;
}

/* 
 * This function will return the length 
 * of the string which is passed as parameter
 */

int my_strlen(char *str)
{
int i = 0;

	/*
	 * For loop will start from index 0 and 
	 * lasts upto not encountered the '\0' (terminating)
	 * character
	 */

	for(i = 0 ; str[i] ; ++i);	

	return i;
}

#endif
