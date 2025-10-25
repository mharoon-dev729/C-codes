#include<stdio.h>
int main()
{
	int latedays,fee;
	
	printf("Enter the no of late days:\n");
	scanf("%d",&latedays);
	
	if(latedays>=1 && latedays<=5)
	{
		fee = 2 * latedays;
		printf("Your total late fee/fine is %d rupees\n",fee);
	}
	
	else if(latedays>=6 && latedays<=10)
	{
		fee = 3 * latedays;
		printf("Your total late fee/fine is %d rupees\n",fee);
	}
	
	else if(latedays>10)
	{
		fee = 5 * latedays;
		printf("Your total late fee/fine is %d rupees\n",fee);
	}
	
	else
	{
		printf("Invalid Input.");
	}
	
	return 0;
}
