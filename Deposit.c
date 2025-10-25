#include<stdio.h>
int main()
{
	int deposit;
	float interest, total;
	
	printf("Enter the amount you deposited from the Bank: \n");
	scanf("%d", &deposit);
	
	if(deposit>=0 && deposit<2000)
	{
		interest = 0.03 * deposit;
		total = interest + deposit;
		
		printf("Interest is %.2f and Total is %.2f \n",interest, total);
	}
	else if(deposit>=2000 && deposit<=10000)
	{
		interest = 0.05 * deposit;
		total = interest + deposit;
		
		printf("Interest is %.2f and Total is %.2f \n",interest, total);
	}
	else if(deposit>10000)
	{
		interest = 0.08 * deposit;
		total = interest + deposit;
		
		printf("Interest is %.2f and Total is %.2f \n",interest, total);
	}
	else
	{
		printf("INVALID INPUT!");
	}
	return 0;
}
