#include<stdio.h>

/*
 * This program count the total character to
 * to remove to make two string anagram
 */

/*
 * Define the macro for 26 character
 */

#define MAX_ALPHA 26

/*
 * This function will take two string and
 * count frequency of character in both string
 * and store them into individual tables
 * after calculating the absolute difference of
 * frequency we can get the total character to remove
 */

int get_char_count(char str1[],char str2[])
{
int i, table1[MAX_ALPHA] = {0} , table2[MAX_ALPHA] = {0}, count = 0, diff = 0;

	for(i = 0 ; str1[i] ; ++i)
		++table1[str1[i] - 'a'];

	for(i = 0 ; str2[i] ; ++i)
		++table2[str2[i] - 'a'];

	for(i = 0 ; i < MAX_ALPHA ; ++i)
	{
		diff = table1[i] - table2[i];

		if(diff < 0)
			diff = (~diff) + 1;
		count += diff;
	}

	return count;
}


int main()
{
char str1[] = "abcdefg";
char str2[] = "acebrui";

	int diff = get_char_count(str1,str2);

	if(diff > 0)
		printf("%d character are required to remove.\n",diff);

	else
		printf("Both string are already anagram.\n");

	return 0;
}
