#include <stdio.h>
int main()
{
    int i, m1, m2, m3, total;
    float percentage;
    char grade;
    
    printf("Grades of 5 students are:\n");
    printf("------------------------------\n");
    
    for (i = 1; i <= 5; i++)
    {
        printf("\nStudent %d\n", i);
        printf("Enter marks of sub 1: ");
        scanf("%d", &m1);
        printf("Enter marks of sub 2: ");
        scanf("%d", &m2);
        printf("Enter marks of sub 3: ");
        scanf("%d", &m3);
        
        total = m1 + m2 + m3;
        percentage = (total / 300.0) * 100;   
        
        if (percentage >= 80 && percentage <= 100)
            grade = 'A';
        else if (percentage >= 70)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 50)
            grade = 'D';
        else if (percentage < 40 && percentage >= 0)
            grade = 'F';
        else {
            printf("INVALID INPUT!\n");
            continue;
        }
        
        printf("Total = %d\tPercentage = %.2f\tGrade = %c\n", total, percentage, grade);
    }
    
    return 0;
}

