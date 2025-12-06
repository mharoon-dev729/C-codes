#include <stdio.h>
#include <stdlib.h>

// Function to compute sum of digits
int sum_of_digits(int num) {
    int sum = 0;
    if (num < 0) num = -num; // handle negative numbers
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to toggle 3rd bit (bit index 2)
int toggle_3rd_bit(int num) {
    return num ^ (1 << 2);
}

// Simple bubble sort using pointer arithmetic
void sort_array(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[15]; // max 15 elements
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i); // pointer arithmetic
    }

    // Process array
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            *(arr + i) = *(arr + i) / 2;
        } else {
            *(arr + i) = sum_of_digits(*(arr + i));
        }

        // Toggle 3rd bit
        *(arr + i) = toggle_3rd_bit(*(arr + i));
    }

    // Sort array
    sort_array(arr, n);

    // Print final array
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}

