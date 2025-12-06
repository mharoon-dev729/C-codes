#include <stdio.h>

int scoreRec(int lvl) {
    if (lvl == 0) return 50;
    return 4 * scoreRec(lvl - 1);
}

int scoreIter(int lvl, int *ans) {
    if (lvl < 0) return 0;
    int s = 50;
    for (int i = 1; i <= lvl; i++)
        s *= 4;
    *ans = s;
    return 1;
}

int main() {
    int choice, lvl, ans;

    while (1) {
        printf("1. Recursive\n2. Iterative\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter level: ");
        scanf("%d", &lvl);

        if (choice == 1)
            printf("Score = %d\n", scoreRec(lvl));
        else {
            if (scoreIter(lvl, &ans))
                printf("Score = %d\n", ans);
        }
    }
    return 0;
}

