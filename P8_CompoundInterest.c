#include <stdio.h>
#include <stdlib.h>

float loop(float p, float r, float t){
    float res = p;
    float factor = (1+(r/100));
    int i;
    for(i=1; i<=t; i++){
        res *= factor;
    }
    res -= p;
    return res;
}

float recursion(float p, float r, float t){
    if(t<=0) return p;
    p *= (1+(r/100));
    return recursion(p, r, t-1);
}

//function pointer in main (define karty waqt hum sirf parameter ki data types btaty hain)
float (*func_array[])(float, float, float) = {loop, recursion};

int main(){
    int choice;
    float p,r,t;
    int c;
    do{
        printf("Enter Principal Amount: ");
        scanf("%f", &p);
        printf("Enter Rate(%): ");
        scanf("%f", &r);
        printf("Enter Time(years): ");
        scanf("%f", &t);
        printf("\n1. Recursive \n2. Loop \n3. Calling Both \n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Answer: %.2f\n\n", recursion(p,r,t) - p);
                break;
            case 2:
                printf("Answer: %.2f\n\n", loop(p,r,t));
                break;
            case 3:
                printf("\nEnter 0 for loop and 1 for recursion: ");
                scanf("%d", &c);
    //(call karty waqt hum sirf parameter without data types btaty hain)
                printf("Answer: %.2f\n\n", func_array[c](p,r,t));
                break;
        }
    }while(choice != 4);
    
}
