#include <stdio.h>
#include <string.h>

// Manual uppercase function (no ctype.h)
void upper(char *s) {
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
}

int main() {
    char names[6][20] = {
        "Ali Raza", "Sara Khan", "Ahmed Malik",
        "Zainab Syed", "Bilal Ansari", "Fatima Iqbal"
    };

    char rolls[6][10];
    char first[20], last[20];
    int i;

    // Generate roll numbers
    for (i = 0; i < 6; i++) {
        sscanf(names[i], "%s %s", first, last);

        rolls[i][0] = (first[0] >= 'a' && first[0] <= 'z') ? first[0] - 32 : first[0];
        rolls[i][1] = (first[1] >= 'a' && first[1] <= 'z') ? first[1] - 32 : first[1];
        rolls[i][2] = (first[2] >= 'a' && first[2] <= 'z') ? first[2] - 32 : first[2];
        rolls[i][3] = (first[3] >= 'a' && first[3] <= 'z') ? first[3] - 32 : first[3];

        rolls[i][4] = '2';
        rolls[i][5] = '5';
        rolls[i][6] = '\0';
    }

    // Search loop
    char input[20];
    while (1) {
        printf("Search roll number (or type END): ");
        scanf("%s", input);

        // Convert user input to uppercase
        upper(input);

        if (strcmp(input, "END") == 0)
            break;

        int found = 0;
        for (i = 0; i < 6; i++) {
            if (strcmp(input, rolls[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (found) printf("FOUND!\n");
        else       printf("NOT FOUND!\n");
    }

    return 0;
}

