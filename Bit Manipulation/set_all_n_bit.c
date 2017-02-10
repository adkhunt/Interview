#include<stdio.h>
#define exit 0

/////////////////////////////////
//			       //
// Program which set all n bit //
//			       //
/////////////////////////////////

void print_binary(int num)
{
int i;

	for(i = 31 ; i >= 0 ; --i)
		printf("%d ",(num>>i)&1);

	printf("\n");
}

int main()
{
int num = 0,n,temp=1;

	printf("Enter number.\n");
	scanf("%d",&n);

	temp = (temp << (n)) - 1 ;

	num = num | temp;

	print_binary(num);

	return exit;
}
