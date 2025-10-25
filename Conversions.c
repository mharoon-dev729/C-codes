#include<stdio.h>
int main()
{
	int type;
	float temp,conversion;
	
	
	printf("Enter 1 for C to F and 2 for F to C: \n");
	scanf("%d",&type);
	
	switch(type)
	{
		case 1:
			printf("Enter temp in Celcius: \n");
			scanf("%f",&temp);
			
			conversion = (1.8*temp)+32;
			
			printf("Temp in Fahrenheit is %.2f degrees\n",conversion);
		break;	
		
		case 2:
			printf("Enter temp in Fahrenheit: \n");
			scanf("%f",&temp);
			
			conversion = (temp-32)/1.8;
			
			printf("Temp in Celsius is %.2f degrees\n",conversion);
		break;
		
		default:
			printf("Invalid input.");
	}
	
	return 0;
}
