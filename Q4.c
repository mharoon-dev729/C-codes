#include <stdio.h>
// structure
struct Book {
    int id;
    int popularity;
    int lastUsed;
};
// FUCNTION main
int main() {
    int capacity, Q;
    scanf("%d %d", &capacity, &Q);
    struct Book shelf[1000];   // max limit safe
    int size = 0;              // no. of current books on shelf
    int timer = 0;             // it increases on every ADD/ACCESS
    while (Q--) {
        char op[10];
        scanf("%s", op);
// to add
        if (op[0] == 'A' && op[1] == 'D') {
            int x, y;
            scanf("%d %d", &x, &y);
            timer++;
            int found = -1;
// check if it already exists
			int i;
            for (i = 0; i < size; i++) {
                if (shelf[i].id == x) {
                    found = i;
                    break;
                }
            }
// if book exists then update and refresh usage
            if (found != -1) {
                shelf[found].popularity = y;
                shelf[found].lastUsed = timer;
            }
            else {
// if shelf full then remove least recently accessed book
                if (size == capacity) {
                    int lraIndex = 0;
                    int i;
                    for (i = 1; i < size; i++)
                        if (shelf[i].lastUsed < shelf[lraIndex].lastUsed)
                            lraIndex = i;
// shift left to remove book at lraIndex
                    for (i = lraIndex; i < size - 1; i++)
                        shelf[i] = shelf[i + 1];
                    size--;
                }
// adding new book
                shelf[size].id = x;
                shelf[size].popularity = y;
                shelf[size].lastUsed = timer;
                size++;
            }
        }
// to access
        else if (op[0] == 'A' && op[1] == 'C') {
            int x;
            scanf("%d", &x);
            timer++;
            int found = -1;
            int i;
            for (i = 0; i < size; i++) {
                if (shelf[i].id == x) {
                    found = i;
                    break;
                }
            }
            if (found == -1) {
                printf("-1\n");
            } else {
                shelf[found].lastUsed = timer;  // mark as recently used
                printf("%d\n", shelf[found].popularity);
            }
        }
    }
    return 0;
}

