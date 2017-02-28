#include<stdio.h>
#include<stdlib.h>
#define max(i,j) (i > j ? i : j)

////////////////////////////////////////////////////
//						  //
// Program to find the longest common subsequence //
//			 			  //
////////////////////////////////////////////////////

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

void longest_common_sequence(char *str1,char *str2)
{
int len1 = my_strlen(str1);
int len2 = my_strlen(str2);
int temp[len1+1][len2+1],i,j;

	for(i = 0 ; i <= len1 ; ++i)
		temp[i][0] = 0;

	for(i = 0 ; i <= len2 ; ++i)
		temp[0][i] = 0;

	for(i = 1 ; i <= len1 ; ++i)
	{
		for(j = 1 ; j <= len2 ; ++j)
		{
			if(str1[i-1] == str2[j-1])
				temp[i][j] = temp[i-1][j-1] + 1;

			else
				temp[i][j] = max(temp[i-1][j],temp[i][j-1]);
		}
	}

	printf("Longest Common Subsequence length = %d\n",temp[len1][len2]);
}

int main()
{
char str1[20],str2[20];

	printf("Enter two strings.\n");
	scanf("%s%s",str1,str2);

	longest_common_sequence(str1,str2);

	return EXIT_SUCCESS;
}
