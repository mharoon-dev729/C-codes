#include <stdio.h>
int main() {
    float temp[7], high;
    int i;
    
    printf("Enter the temperature on Day 1\n");
    scanf("%f", &temp[0]);
    high = temp[0];
    
    for(i = 1; i < 7; i++) {
        printf("Enter the temperature on Day %d\n", i + 1);
        scanf("%f", &temp[i]);
        
        if(temp[i] > high) {
            high = temp[i];
        }
    }
    
    printf("\nThe hottest temperature recorded in the week is: %.2fCelsius\n", high);
    return 0;
}

