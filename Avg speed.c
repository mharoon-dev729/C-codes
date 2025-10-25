#include<stdio.h>
int main()
{
	float distance, time ,speed;
	
	printf("Enter total distance in km\n");
	scanf("%f", &distance);
	printf("Enter total total in hr\n");
	scanf("%f", &time);
	
	if(time<=0)
	{
		printf("Time is undetermined.\n");
		return 1;
	}
	
	
	speed = distance / time;
	
	printf("Speed is %.2f km/hr\n", speed);
	if(speed<0)
	{
		printf("Speed is decreasing.");
	}
	
	return 0;
}
