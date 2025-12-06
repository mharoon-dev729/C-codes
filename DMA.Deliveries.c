#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, new_n, i;
    printf("How many deliveries currently? ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (i = 0; i < n; i++) {
        printf("Enter distance %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Any update in deliveries? Enter new total: ");
    scanf("%d", &new_n);

    arr = (int*)realloc(arr, new_n * sizeof(int));
    if (arr == NULL) return 1;

    if (new_n > n) {
        for (i = n; i < new_n; i++) {
            printf("Enter distance %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }

    int total = 0;
    printf("\nFinal Delivery Route (Total: %d)\n", new_n);
    for (i = 0; i < new_n; i++) {
        printf("Delivery %d: %d km\n", i+1, arr[i]);
        total += arr[i];
    }

    printf("Total distance: %d km\n", total);

    free(arr);
    return 0;
}

