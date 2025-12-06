#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to count using pointers
void count_chars(char *p, int *upper, int *lower, int *digit, int *special) {
    while (*p) {
        if (*p >= 'A' && *p <= 'Z') (*upper)++;
        else if (*p >= 'a' && *p <= 'z') (*lower)++;
        else if (*p >= '0' && *p <= '9') (*digit)++;
        else (*special)++;
        p++;   // pointer move
    }
}

// Recursive reverse + modification
void reverse_modify(char *start, char *end) {
    if (start >= end) return;

    // swap characters
    char temp = *start;
    *start = *end;
    *end = temp;

    reverse_modify(start + 1, end - 1);
}

// Modify reversed string
void transform(char *p) {
    while (*p) {
        if (*p >= 'A' && *p <= 'Z')
            *p = *p + 32;             // upper ? lower
        else if (*p >= 'a' && *p <= 'z')
            *p = *p - 32;             // lower ? upper
        else if (*p >= '0' && *p <= '9')
            *p = '*';                 // digits ? *
        p++;
    }
}

int main() {
    char s[200];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline
    s[strcspn(s, "\n")] = '\0';

    int upper = 0, lower = 0, digit = 0, special = 0;

    // Counting
    count_chars(s, &upper, &lower, &digit, &special);

    int n = strlen(s);

    // Reverse recursively
    reverse_modify(s, s + n - 1);

    // Transform after reverse
    transform(s);

    // Output
    printf("\nModified Reversed String: %s\n", s);
    printf("Uppercase Count: %d\n", upper);
    printf("Lowercase Count: %d\n", lower);
    printf("Digits Count: %d\n", digit);
    printf("Special Characters Count: %d\n", special);

    return 0;
}

