#include<stdio.h>
#include<stdlib.h>
#include"trie.h"

//////////////////////////////////
//				//
// Count the word in given file //
//				//
//////////////////////////////////

int my_strlen(char *str)
{
int i = 0;

	while(str[i])
		++i;

	return i;
}

void remove_symbol(char *str)
{
int len = my_strlen(str);
int i,flag = 0;

	if((str[0] <= 'A' || str[0] >= 'Z') && (str[0] <= 'a' || str[0] >= 'z'))
	{
		flag = 1;
		for(i = 1 ; str[i] ; ++i)
			str[i-1] = str[i];
		str[i-1] = '\0';
	}

	if(flag)
	{
		if((str[len-2] <= 'A' || str[len-2] >= 'Z') && (str[len-2] <= 'a' || str[len-2] >= 'z'))
			str[len-2] = '\0';
	}

	else
	{
		if((str[len-1] <= 'A' || str[len-1] >= 'Z') && (str[len-1] <= 'a' || str[len-1] >= 'z'))
			str[len-1] = '\0';
	}
}

int main()
{
node *data = (node*) malloc(sizeof(node));
FILE *fp = null;
char str[20];
char *temp = null;

	fp = fopen("data","r");

	if(fp == null)
	{
		printf("File can't open.\n");
		return 1;
	}

	while((fscanf(fp,"%s",str))!=EOF)
	{
		remove_symbol(str);
		insert_word(&data,str);
	}

	temp = (char*) malloc(sizeof(char)*20);

	print_word(data,temp,0);

	return EXIT_SUCCESS;
}
