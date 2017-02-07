#include<stdio.h>
#define exit 0

//////////////////////////////////////////
//					//
// Program to find the square root of   //
// Given number without using sqrt fun  //
//					//
//////////////////////////////////////////

int my_sqrt(int num)
{
int start = 1,end = num,mid,x,ans;

	if(num==0 || num == 1)
		return num;

	while(start<=end){

		mid = (start+end)/2;

		if((mid*mid) == num)
			return mid;

		if((mid*mid) < num){
		
			start = mid+1;
			ans = mid;
		}else{
			end = mid-1;
		}
	}

	return ans;
}

int main()
{
int num;

	printf("Enter number to find root of number.\n");
	scanf("%d",&num);

	int res = my_sqrt(num);

	printf("Square root of %d = %d\n",num,res);

	return exit;
}
