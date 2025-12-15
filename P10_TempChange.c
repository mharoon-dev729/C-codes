#include <stdio.h>
#include <stdlib.h>

float recursion(int years, float temp){
	if(years == 0) return temp;
	
	float x;
	printf("change in temp?");
	scanf("%f", &x);
	
	recursion(years - 1, temp + x);
}

float loop(int years, float temp){
	int i;
	float y;
	for(i=0;i<years;i++){
		printf("change in temp?");
		scanf("%f", &y);
		temp+=y;
	}
	return temp;
}

float (*option[])(int, float) = { recursion, loop };

int main(){
	int years;
	scanf("%f", &years);
	int choice;
	int c;
	while(1){
		printf("1 = recursion 2 = loop 3 = both 4 = exit");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("result = %.2f", recursion(years, 0)); break;
			case 2: printf("result = %.2f", loop(years, 0)); break;
			case 3: printf("0 = recursion 1 = loop");
					scanf("%d", &c);
					float ans = option[c](years, 0);
					printf("%.2f", ans);
					break;
		}	
	}
	return 0;
}
