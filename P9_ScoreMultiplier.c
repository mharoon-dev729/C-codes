#include <stdio.h>
#include <stdlib.h>

float recursion(float base, float level){
	//base case
	if(level==0) return base;

	base*=base;
	recursion(base, level - 1);
}

float loop(float base, float level){
	int i;
	for(i=0;i<level;i++){
		base*=base;
	}
	return base;
}

float (*option[])(float, float) = { recursion, loop };
					
int main(){
	float base, level;
	scanf("%f %f", &base, &level);
	int c;
	while(1){
		int choice;
		printf("1->Recursion\n2-> Loop\n3-> Both\n-> Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("%.2f", recursion(base, level)); break;
			case 2: printf("%.2f", loop(base, level)); break;
			case 3:	printf("0 = recursion\n 1 = loop\n");
					scanf("%d", &c);
					float res = option[c](base, level);
					printf("result = %.2f", res); 	break;
			case 4: return 0;
		}
	}
	
	return 0;
}
