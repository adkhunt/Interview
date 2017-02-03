#ifndef string
#define string

#include<stdio.h>
#include<stdlib.h>
#define null NULL

char* getString(void)
{
char *ret = null,ch;
int i = 0;

	ret = (char*) malloc(sizeof(char));

	while((ch=getc(stdin)) != '\n')
	{
		ret[i++] = ch;
		ret = realloc(ret,i+1);
	}

	ret[i] = '\0';

	return ret;
}

int my_strlen(char *str)
{
int i = 0;

	for(i = 0 ; str[i] ; ++i);	

	return i;
}

#endif
