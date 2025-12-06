#include <stdio.h>

int visitorsRecursive(int d) {
    if (d == 0) return 100;
    return 3 * visitorsRecursive(d - 1);
}

int visitorsIterative(int d, int *ans) {
    if (d < 0) return 0;
    int v = 100, i;
    for (i = 1; i <= d; i++){
       v = v * 3;
   }
    *ans = v;
    return 1;
}

int main() {
    int choice, days, ans;

    while (1) {
        printf("=== Website Traffic Analyzer ===\n");
        printf("1. Recursive Calculation\n");
        printf("2. Iterative Calculation (using pointer)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter number of days (0 to 20): ");
        scanf("%d", &days);

        if (choice == 1) {
            printf("Visitors = %d\n", visitorsRecursive(days));
        }
        else if (choice == 2) {
            if (visitorsIterative(days, &ans))
                printf("Visitors = %d\n", ans);
            else
                printf("Invalid days!\n");
        }
    }
    return 0;
}

