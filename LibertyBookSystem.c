#include <stdio.h>
#include <string.h>
#define MAX 100

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount);
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);

int main() {
    int isbns[MAX];
    char titles[MAX][50];
    float prices[MAX];
    int quantities[MAX];
    int bookCount = 0;
    int choice;

    printf("----- Welcome to Liberty Books Inventory System -----\n");

    while (1) {
        printf("\n==============================\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &bookCount);
                break;
            case 2:
                processSale(isbns, titles, prices, quantities, bookCount);
                break;
            case 3:
                generateLowStockReport(isbns, titles, prices, quantities, bookCount);
                break;
            case 4:
                printf("Exiting program... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount) {
    int n, i;
    printf("How many books do you want to add? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (*bookCount >= MAX) {
            printf("Inventory full! Cannot add more books.\n");
            return;
        }

        printf("\n--- Adding Book %d ---\n", *bookCount + 1);

        printf("Enter ISBN: ");
        scanf("%d", &isbns[*bookCount]);

        int duplicate = 0, j;
        for (j = 0; j < *bookCount; j++) {
            if (isbns[j] == isbns[*bookCount]) {
                printf("ISBN already exists! Skipping...\n");
                duplicate = 1;
                break;
            }
        }
        if (duplicate) continue;

        printf("Enter Title: ");
        scanf(" %[^\n]", titles[*bookCount]);

        printf("Enter Price: ");
        scanf("%f", &prices[*bookCount]);

        printf("Enter Quantity: ");
        scanf("%d", &quantities[*bookCount]);

        (*bookCount)++;
    }

    printf("\nBook(s) added successfully!\n");
}

void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    int isbn, qty, i;

    if (bookCount == 0) {
        printf("No books in inventory!\n");
        return;
    }

    printf("\nEnter ISBN of book sold: ");
    scanf("%d", &isbn);

    for (i = 0; i < bookCount; i++) {
        if (isbns[i] == isbn) {
            printf("Enter quantity sold: ");
            scanf("%d", &qty);

            if (qty > quantities[i]) {
                printf("Not enough stock available!\n");
            } else {
                quantities[i] -= qty;
                float total = qty * prices[i];
                printf("Sale processed for \"%s\". Total: Rs. %.2f\n", titles[i], total);
            }
            return;
        }
    }

    printf("Book with ISBN %d not found!\n", isbn);
}

void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    int found = 0, i;

    printf("\n----- LOW-STOCK REPORT (Quantity < 5) -----\n");

    for (i = 0; i < bookCount; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: Rs. %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("All books have sufficient stock.\n");
}

