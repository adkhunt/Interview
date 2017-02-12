#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

/////////////////////////////////////////////////////
//						   //
// Program to perform run length encoding(String - //
// Compression)					   //
//						   //
/////////////////////////////////////////////////////

int my_strlen(char *str)
{
int i;

	for(i = 0 ;str[i] ; ++i);

	return i;
}

void my_strcpy(char *dest,char src[])
{
int new_len = my_strlen(src),i;

	dest = (char*) realloc(dest,new_len+1);

	for(i = 0 ; src[i] ; ++i)
		dest[i] = src[i];

}

void perform_RLE(char *str)
{
char temp[my_strlen(str)*2+1];
int i=0,j,count = 1,index = 0;

	while(str[i])
	{
		j = i + 1;

		while(str[j] == str[i])
			++j,++count;

		temp[index++] = str[i];
		temp[index++] = count+48;

		count = 1;
		i = j;
	}

	my_strcpy(str,temp);
}

int main()
{
char *str = (char*) malloc(sizeof(char));
char ch;
int i = 0;

	printf("Enter string to convert in run-lenght-encoding.\n");
	
	while((ch = fgetc(stdin)) != '\n')
	{
		str[i] = ch;
		++i;
		str = (char*) realloc(str,i+1);
	}

	printf("String = %s\n",str);

	perform_RLE(str);

	printf("New String = %s\n",str);

	return exit;
}
