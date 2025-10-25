#include<stdio.h>
int main ()
{
	int i;
	float principal,rate,interest,years;
	
	for(i=1; ;i++)
	{
		printf("Enter Principal \n");
		scanf("%f",&principal);
		printf("Enter Years \n");
		scanf("%f",&years);
		printf("Enter Rate \n");
		scanf("%f",&rate);
		
		interest = (principal * rate * years) / 100;
		
		printf("Your total interest is %.2f percentage\n", interest);
		
		if(principal<=0 || rate<0 || years<=0)
		{
			printf("INVALID INPUTS!");
		}
		break;
	}
	return 0;
}
