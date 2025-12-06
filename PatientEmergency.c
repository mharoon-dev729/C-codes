#include <stdio.h>
#include <string.h>

// manual uppercase converter (no ctype.h)
void upper(char *s) {
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32; // convert to uppercase
        }
    }
}

// convert single char uppercase
char up(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

int main() {
    char patients[6][30] = {
        "Sana Malik", "Imran Qureshi", "Nadia Ahmed",
        "Kamran Shah", "Hira Butt", "Tariq Jamil"
    };

    char codes[6][20];
    char code[20];

    // generate codes
    int i;
    for (i = 0; i < 6; i++) {
        char first[20], last[20];
        sscanf(patients[i], "%s %s", first, last);

        snprintf(codes[i], 20, "%c%c%c%c%cER",
            up(first[0]), up(first[1]),
            up(last[0]),  up(last[1]), up(last[2])
        );
    }

    while (1) {
        printf("Enter patient code (or STOP): ");
        scanf("%s", code);
        upper(code);

        if (strcmp(code, "STOP") == 0) break;

        int found = 0;
        for (i = 0; i < 6; i++) {
            if (strcmp(code, codes[i]) == 0) {
                printf("Patient: %s\n", patients[i]);
                found = 1;
                break;
            }
        }

        if (!found) printf("Patient not found!\n");
    }

    return 0;
}

