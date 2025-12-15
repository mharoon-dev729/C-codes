#include <stdio.h>
#include <stdlib.h>

struct Valve {
    char name[20];
    int id;
    int status;
};

void openValve(struct Valve *v) {
    v->status = 1;
}

void closeValve(struct Valve *v) {
    v->status = 0;
}

void toggleValve(struct Valve *v) {
    v->status = !v->status;
}

void (*operations[])(struct Valve *) = {openValve, closeValve, toggleValve};

int main() {

    int n;
    scanf("%d", &n);

    struct Valve *valve = malloc(n * sizeof(struct Valve));

    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %d", valve[i].name, &valve[i].id);
        valve[i].status = 0;
        
        int choice;
    printf("0 = Open\n1 = Close\n2 = Toggle\n");
    scanf("%d", &choice);

        operations[choice](&valve[i]);
    }

    for (i = 0; i < n; i++) {
        printf("%s %d -> %s\n", valve[i].name, valve[i].id, valve[i].status ? "OPEN" : "CLOSED");
    }

    free(valve);
    return 0;
}

