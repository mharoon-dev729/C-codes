#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, new_n;
    printf("How many seats booked? ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        printf("Seat %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Any booking changes? New total seats: ");
    scanf("%d", &new_n);

    arr = realloc(arr, new_n * sizeof(int));
    if (arr == NULL) return 1;

    if (new_n > n) {
        for (int i = n; i < new_n; i++) {
            printf("Seat %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    }

    printf("\nFinal Booking List (Total %d)\n", new_n);
    for (int i = 0; i < new_n; i++)
        printf("Seat %d: %d\n", i+1, arr[i]);

    free(arr);
    return 0;
}

