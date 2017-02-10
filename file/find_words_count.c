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

void remove_last_symbol(char *str)
{
int len = my_strlen(str);

	if((str[len-1] < 'A' || str[len-1] > 'Z') && (str[len-1] < 'a' || str[len-1] > 'z'))
		str[len-1] = '\0';
}

int main()
{
node *data = (node*) malloc(sizeof(node));
FILE *fp = null;
char str[20];

	fp = fopen("data","r");

	if(fp == null)
	{
		printf("File can't open.\n");
		return 1;
	}

	while((fscanf(fp,"%s",str))!=EOF)
	{
		remove_last_symbol(str);
		insert_word(&data,str);
	}

	print_word(data);

	return EXIT_SUCCESS;
}
