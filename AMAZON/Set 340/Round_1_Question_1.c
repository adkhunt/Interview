#include<stdio.h>
#include<stdlib.h>

void run_length_encodding(char *str)
{
int i = 0,j = 0,index = 0;

	while(str[i])
	{
		j = i;

		while(str[i] == str[j])
			++j;

		str[index++] = str[i];
		str[index++] = (char) (j - i) + 48;
		
		i = j;
	}

	str[index] = '\0';
}

int main()
{
char str[20];

	printf("Enter string to perform run-length encodding.\n");
	scanf("%s",str);

	run_length_encodding(str);

	printf("Result = %s\n",str);

	return EXIT_SUCCESS;
}
