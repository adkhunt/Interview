#include<stdio.h>
#include<stdlib.h>

/*
 * Program to multiply the large number
 * stored in the string
 */

/*
 * This function will return the length of the 
 * string
 */

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

/*
 * This function will multiply the string 
 * and store the result into the res string
 * and return that string.
 */

char* multiply(char *num1, char *num2)
{
int len1 = my_strlen(num1);
int len2 = my_strlen(num2);
int len = len1+len2+1;
int i, j, k, carry, rem, sum;

char* res = NULL;

	res = (char*) malloc(sizeof(char)*len);

	res[len-1] = 0;
	--len;

	for(i = 0 ; i < len ; ++i)
		res[i] = '0';

	for(i = len2 - 1 ; i >= 0 ; --i)
	{
		k = len - (len2 - i);
		carry = 0;

		for(j = len1-1 ; j >= 0 ; --j)
		{
			sum = ((num2[i] - '0') * (num1[j] - '0')) + carry +
					(res[k] - '0');

			carry = sum / 10;
			sum = sum % 10;

			res[k] = (char) (sum + '0');
			--k;
		}

		if(carry > 0)
			res[k] = (char) (carry + '0');
	}
	
	return res;
}

int main()
{
char num1[20],num2[20];

	printf("Enter two large numbers.\n");
	scanf("%s",num1);
	scanf("%s",num2);

	char *res = multiply(num1, num2);

	printf("Res = %s\n",res);

	return 0;
}
