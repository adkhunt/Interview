#include<stdio.h>
#include"string.h"
#define exit 0

///////////////////////////////////////////////////
//						 //
// Remove consicutive spaces in the given string //
//						 //
///////////////////////////////////////////////////

void remove_Space(char *str)
{
int i,j,count;

	for(i = 0 ; str[i] ; ++i)
	{
		j = i;
		count = 0;
		while(str[i] == ' ' && str[i+1] == ' ')
		{
			++i;
			++count;
		}

		if(j != i)
		{
			int n = i;
			for(j ; str[j] ; ++j)
				str[j] = str[n++];
		}
	}
}

int main()
{
char *str = null;

	printf("Enter string to remove consicutive space.\n");
	str = getString();

	remove_Space(str);

	printf("New String = %s\n",str);

	return exit;
}
