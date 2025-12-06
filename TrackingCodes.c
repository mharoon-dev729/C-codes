#include <stdio.h>
#include <string.h>

void upper(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;   // convert manually
        }
    }
}

int main() {
    char names[6][30] = {
        "Hamza Tariq", "Ayesha Noor", "Usman Farooq",
        "Madiha Ali", "Saad Hassan", "Rabia Shah"
    };

    char codes[6][20], in[20];

    // code generation
    for (int i = 0; i < 6; i++) {
        char first[20], last[20];
        sscanf(names[i], "%s %s", first, last);

        snprintf(codes[i], 20, "%c%c%c%c%cPK",
            (first[0] >= 'a' ? first[0] - 32 : first[0]),
            (first[1] >= 'a' ? first[1] - 32 : first[1]),
            (last[0]  >= 'a' ? last[0]  - 32 : last[0]),
            (last[1]  >= 'a' ? last[1]  - 32 : last[1]),
            (last[2]  >= 'a' ? last[2]  - 32 : last[2])
        );
    }

    while (1) {
        printf("Enter tracking code (or QUIT): ");
        scanf("%s", in);
        upper(in);

        if (strcmp(in, "QUIT") == 0) break;

        int found = 0;
        for (int i = 0; i < 6; i++) {
            if (strcmp(in, codes[i]) == 0) {
                printf("Sender: %s\n", names[i]);
                found = 1;
                break;
            }
        }
        if (!found) printf("Not found!\n");
    }

    return 0;
}

