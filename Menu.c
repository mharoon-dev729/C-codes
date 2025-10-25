#include<stdio.h>
int main()
{
	int choice, quantity, bill;
	
	printf("Enter 1 for Tea 2 for Burger 3 for Pizza and 4 for Sandwich: \n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter the quantity of Tea: \n");
			scanf("%d", &quantity);
			bill = 50 * quantity;
			printf("The total bill is %d\n", bill);
		case 2:
			printf("Enter the quantity of Burger: \n");
			scanf("%d", &quantity);
			bill = 150 * quantity;
			printf("The total bill is %d\n", bill);
		case 3:
			printf("Enter the quantity of Pizza: \n");
			scanf("%d", &quantity);
			bill = 300 * quantity;
			printf("The total bill is %d\n", bill);
		case 4:
			printf("Enter the quantity of Sandwich: \n");
			scanf("%d", &quantity);	
			bill = 100 * quantity;
			printf("The total bill is %d\n", bill);
		default:
			printf("INVALID INPUTS");
	}
	return 0;
}
