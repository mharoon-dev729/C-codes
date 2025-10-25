#include<stdio.h>
int main()
{
	int expense,total=0,i;
	float avg;
	
	for(i=1;i<=7;i++)
	{
		printf("Enter your Daily Expense:\n");
		scanf("%d",&expense);
		
		total = total + expense;
		
		if(expense == 0)
		{
			printf("WARNING! You should have spend some moeny.\n");
		}
	}
		printf("Total amount is %d\n", total);
	avg = total / 7;
		
	if(avg<500)
	{
		printf("%.2f is a Budget Friendly avg.\n",avg);
	}
	else
	{
		printf("You are overspending.");
	}
	
	return 0;
}
