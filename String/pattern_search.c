#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define exit_success 0

////////////////////////////////////////////////
//					      //
// Program to find the pattern in O(m+n) time //
// In main string			      //
//					      //
////////////////////////////////////////////////

int* Build_array(char *str,int size)
{
int i =1 , j =0;
int *a = (int*) calloc(sizeof(int),size);

	while(i<size)
	{
		if(str[i] == str[j])
		{
			a[i] = j+1;
			++i,++j;
		}

		else
		{
			if(j!=0)
			{
				j = a[j-1];
			}

			else
			{
				a[i] = 0;
				++i;
			}
		}
	}

	return a;
}

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

int Kmp_Search(char *main_string,char *pattern)
{
int main_len = my_strlen(main_string);
int pat_len = my_strlen(pattern),i = 0,j=0;
int *arr = Build_array(main_string,main_len);

	for(i = 0 ; i < main_len ; ++i)
		printf("%d ",arr[i]);
	printf("\n");
	i=0;

	while(main_string[i])
	{
		if(j == pat_len)
		{
			return i-pat_len;
		}

		if(main_string[i] == pattern[j])
		{
			++i,++j;
		}

		else
		{
			if(j!=0)
				j = arr[j-1];

			else
				++i;
		}		
	}

	return 0;
}

char* getString(void)
{
int i = 0;
char *str = (char*) malloc(sizeof(char)*1),ch;

	while((ch = fgetc(stdin)) != '\n')
	{
		str[i++] = ch;
		str = (char*) realloc(str,i+1);
	}

	str[i] = '\0';

	return str;
}

int main()
{
char *main_string = null,*pattern_string = null;
int i;

	printf("Enter main string.\n");
	main_string = getString();
	
	printf("Enter pattern to search.\n");
	pattern_string = getString();

	printf("Main String : %s\n",main_string);
	printf("Pattern : %s\n",pattern_string);

	int index = Kmp_Search(main_string,pattern_string);

	if(index != 0)
		printf("Pattern found at %d index\n",index);

	else
		printf("No such pattern found in string.\n");

	return exit_success;
}
