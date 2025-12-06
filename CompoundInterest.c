#include <stdio.h>

float AmountRec(int y) {
    if (y == 0) return 10000;
    return 1.1 * AmountRec(y - 1);
}

int AmountIter(int y, float *ans) {
    if (y < 0) return 0;
    float a = 10000;
    for (int i = 1; i <= y; i++)
        a *= 1.1;
    *ans = a;
    return 1;
}

int main() {
    int choice, years;
    float ans;

    while (1) {
        printf("=== Compound Interest Calculator ===\n");
        printf("1. Recursive\n2. Iterative\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter years: ");
        scanf("%d", &years);

        if (choice == 1)
            printf("Amount = %.2f\n", AmountRec(years));
        else
            if (AmountIter(years, &ans))
                printf("Amount = %.2f\n", ans);
    }
    return 0;
}

