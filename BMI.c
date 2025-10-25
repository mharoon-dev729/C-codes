#include <stdio.h>
int main()
{
    float weight, height, BMI;

    printf("Enter your weight in kg\n");
    scanf("%f", &weight);
    printf("Enter your height in m\n");
    scanf("%f", &height);

    if(weight <= 0 || height <= 0) {
        printf("INVALID INPUT!\n");
        return 0;
    }

    BMI = weight / (height * height);

    if(BMI > 0 && BMI < 18.5)
    {
        printf("BMI is %.2f\n", BMI);
        printf("You are underweight.\n");
    }
    else if(BMI >= 18.5 && BMI <= 24.9)
    {
        printf("BMI is %.2f\n", BMI);
        printf("You are Normal.\n");
    }
    else if(BMI >= 25 && BMI <= 29.9)
    {
        printf("BMI is %.2f\n", BMI);
        printf("You are overweight.\n");
    }
    else if(BMI >= 30)
    {
        printf("BMI is %.2f\n", BMI);
        printf("You are obese.\n");
    }
    else
    {
        printf("INVALID INPUT!\n");
    }

    return 0;
}

