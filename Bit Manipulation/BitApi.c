#include<stdio.h>
#define exit 0

///////////////////////////////////////////////
//					     //
// Function to set clear and toogle the bits //
// Of number				     //
//					     //
///////////////////////////////////////////////

int SetBit(int *num,int BitPosition)
{
	*num = (*num) | (1 << BitPosition);
}

void ClearBit(int *num,int BitPosition)
{
	*num = (*num) & ~(1<<BitPosition);
}

void ToogleBit(int *num,int BitPosition)
{
	*num = (*num) ^ (1 << BitPosition);
}

void PrintBinary(int num)
{
int i;

	for(i = 31 ; i >= 0 ; --i)
	{
		printf("%d",(num>>i)&1);
		if(i%8 == 0)
			printf(" ");
	}

	printf("\n");
}

int main()
{
int num;

	printf("Enter number.\n");
	scanf("%d",&num);

	PrintBinary(num);
	SetBit(&num,14);
	PrintBinary(num);
	ClearBit(&num,3);
	PrintBinary(num);
	ToogleBit(&num,14);
	PrintBinary(num);

	return exit;
}
