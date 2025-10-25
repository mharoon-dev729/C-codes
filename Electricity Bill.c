#include<stdio.h>
int main()
{
	int units,bill;
	
	printf("Enter the Electricity units: \n");
	scanf("%d",&units);
	
	if(units<100)
	{
		bill=5*units;
		printf("Your bill is %d\n",bill);
	}
	else if(units>=100 && units<=300)
	{
		bill=(100*5)+((units-100)*7);
		printf("Your bill is %d\n",bill);
	}
	else if(units>300)
	{
		bill=(100*5)+(200*7)+((units-300)*10);
		printf("Your bill is %d\n",bill);
	}
	else
	{
		printf("Invalid input");
	}
	
	return 0;
}
