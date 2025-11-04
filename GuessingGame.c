#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess();
int n, count = 0;

int main() {
    int choice;
    srand(time(NULL));  // ensure new random number each run
    n = rand() % 100 + 1;

    printf("WELCOME TO GUESSING GAME\n");

    while (1) {
        printf("Enter your Choice:\n1. To Play Game\n2. To Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: guess(); break;
            case 2: printf("Exiting...\n"); return 0;
            default: printf("Invalid Input!\n");
        }
    }
}

void guess() {
    int num;
    while (1) {
        printf("Enter a number to guess (1-100): ");
        scanf("%d", &num);
        count++;

        if (num > n)
            printf("Too high! Try again.\n");
        else if (num < n)
            printf("Too low! Try again.\n");
        else {
            printf("Correct! You guessed it in %d attempts!\n", count);
            count = 0;  // reset for next game
            n = rand() % 100 + 1;  // generate new number for next round
            break;
        }
    }
}

