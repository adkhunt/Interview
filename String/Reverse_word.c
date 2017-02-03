#include<stdio.h>
#include"string.h"
#define exit 0
#define String char*

/////////////////////////////////////////////////
//					       //
// Program to reverse words of string and also //
// Whole string				       //
//					       //
/////////////////////////////////////////////////

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void Reverse_String(String str)
{
int n = my_strlen(str) - 1;
int i = 0;

	while(i < n)
	{
		swap(&str[i],&str[n]);
		--n,++i;
	}
}

void Reverse_words(String str)		
{
int i,j,n;
int len = my_strlen(str);

	for(i = 0 ; i<= len ; ++i)
	{
		j = i;

		while(str[i] != ' ' && str[i] != '\0')
			++i;

		n = i-1;

		while(j < n)
		{
			swap(&str[j],&str[n]);
			--n,++j;
		}
	}
}

int main()
{
String str = null;

	printf("Enter string.: ");
	str = getString();

	printf("String = %s\n",str);
	Reverse_words(str);		//Reverse the wors of string
	printf("New String = %s\n",str);
	Reverse_String(str);		// Reverse whole string 
	printf("New String = %s\n",str);

	return exit;
}
