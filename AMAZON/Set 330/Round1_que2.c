/* Program to count the characters and digits in
 * given string
 */

#include<stdio.h>
#define exit_success 0

/* struct variable to store digit_count
 * and character count and this will returned to 
 * main function
 */

struct count_pair{
			int digit_count;
			int char_count;
};

/* function to count the digits and characters in 
 * string entered by the user we declared the structure 
 * which contain two integer which is the count result
 * we declared that as static because we are going to return that
 * structure (See Scope of Static http://quiz.geeksforgeeks.org/static-variables-in-c/)
 * we initialise the both variable with zero now we iterate through string
 * we check each character and accordingly 
 */

struct count_pair count_char_dig(char *str)
{
int i;
static struct count_pair result;

	result.digit_count = 0;
	result.char_count = 0;

	for(i = 0 ; str[i] ; ++i)
	{
		if(str[i] >= 'a' && str[i] <='z')
			++result.char_count;

		else if(str[i] >= 'A' && str[i] <= 'Z')
			++result.char_count;

		else if(str[i] >= '0' && str[i] <= '9')
			++result.digit_count;
	}

	return result;
}

int main()
{
char str[20];

	/* prompt to user to enter string
	 * that contain digits , symbols &
	 * characters
	 */

	printf("Enter String contain with digits,symbols and chars.\n");
	scanf("%s",str);

	/* call the function which complete the 
	 * counting operation in string
	 */

	struct count_pair res = count_char_dig(str);

	printf("Digit = %d\tChar = %d\n",res.digit_count,res.char_count);

	/* return to main parent that task completed 
	 * successfully
	 */
	return exit_success;
}
