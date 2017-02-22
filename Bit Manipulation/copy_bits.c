#include<stdio.h>

///////////////////////////////////////////////
//				  	     //
// Copy the bits from one num to second from //
// given location 			     //
//					     //
///////////////////////////////////////////////

int copy_bits(int x,int y,int p,int q)
{
int i,start = 0 ,bit;

	for(i = p ; i <= q ; ++i)
	{
		bit = (x>>i)&1;
		if(bit)
			y = y | (1<<start);

		else
			y = y & ~(1<<start);

		++start;
	}

	return y;
}

void print_binary(int num)
{
int i;

	for(i = 31 ; i>= 0 ; --i)
	{
		printf("%d",(num>>i)&1);

		if(i%8 == 0)
			printf(" ");
	}

	printf("\n");
}

int main()
{
int x = 0x0abc349d;
int y = 0x0def1255;
int p,q;

	printf("Enter \"p\" and \"q\" Location.\n");
	scanf("%d%d",&p,&q);

	int ret = copy_bits(x,y,p,q);

	printf("x = ");
	print_binary(x);
	printf("y = ");
	print_binary(y);
	printf("ret = ");
	print_binary(ret);

	printf("Result = %p\n",ret);	

	return 0;
}
