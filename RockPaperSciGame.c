#include<stdio.h>
#include<stdlib.h>
void winner();
int choice, num;
int main(){
	printf("WELCOME TO GAME\n");
	printf("=================\n");
	while(1){
		printf("YOUR DECISION........\n");
		printf("=================\n");
		printf("Enter your choice: \n1. Rock\n2. Paper\n3. Scissor\n4. To Exit\n");
		printf("=================\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: winner(); break;
			case 2: winner(); break;
			case 3: winner(); break;
			case 4: printf("Exiting...!"); return 0;
			default: printf("Invalid Input\n");
		}
	}
}
void winner(){
	num = rand() % 3 + 1;
	printf("COMPUTER DECISION.......\n");
	if(num == 1){
		printf("Computer chose Rock\n");
	}
	if(num == 2){
		printf("Computer chose Paper\n");
	}
	if(num == 3){
		printf("Computer chose Scissor\n");
	}
	printf("=================\n");
	if((choice == 2 && num == 1) || (choice == 3 && num == 2) || (choice == 1 && num == 3)){
		printf("You have won!\n");
	printf("=================\n");
	}
	else if((choice == 1 && num == 2) || (choice == 2 && num == 3) || (choice == 3 && num == 1)){
		printf("Computer has won!\n");
	printf("=================\n");
	}
	else{
		printf("The GAME is TIE!\n");
		printf("Let's Play Again\n");
	printf("=================\n");
	printf("=================\n");
	}
}
