#include<stdio.h>
#include<math.h>
int main()
{
	int num,temp,count = 0,digit;
	int sum = 0;
	printf("Enter number: \n");
	scanf("%d",&num);
	
	temp = num;
	while(temp>0)
	{
		count++;
		temp = temp / 10;
	}
	
	temp = num;
	while(temp>0)
	{
		digit = temp % 10;
		sum = sum + pow(digit,count);
		temp = temp / 10;
	}
	
	if(num == sum)
	{
		printf("ARMSTRONG NUMBER.\n");
	}
	else
	{
		printf("NOT ARMSTRONG.\n");
	}
	
	return 0;
}
