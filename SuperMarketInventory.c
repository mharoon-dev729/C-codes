#include <stdio.h>
#include <string.h>
#define MAX 20

void information(char name[], char cnic[]);
void fillInventory(int productCode[], int quantity[], float pricePerProduct[]);
void displayInventory(int productCode[], int quantity[], float pricePerProduct[]);
void cart(int productCode[], int quantity[], float pricePerProduct[]);
void updateInventory(int productCode[], int quantity[], float pricePerProduct[]);
void bill(int productCode[], int quantity[], float pricePerProduct[], char promoCode[]);
void invoice(char name[], char cnic[], int productCode[], int quantity[], float pricePerProduct[]);

int n = 0, g = 0, f = 0, ifFound = 0;
float totalBill = 0, discount = 0;

int main() {
    char name[MAX], cnic[15], promoCode[MAX];
    int productCode[MAX], quantity[MAX];
    float pricePerProduct[MAX];
    int choice;

    printf("----- Welcome to XYZ SuperMarket -----\n");

    while (1) {
        printf("\n------------------------------------\n");
        printf("1. Enter Customer Information\n");
        printf("2. Fill the Inventory\n");
        printf("3. Display the Inventory\n");
        printf("4. Add to Cart\n");
        printf("5. Update Inventory\n");
        printf("6. Check Bill\n");
        printf("7. Print Invoice\n");
        printf("8. Exit Program\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                information(name, cnic);
                break;
            case 2:
                fillInventory(productCode, quantity, pricePerProduct);
                break;
            case 3:
                displayInventory(productCode, quantity, pricePerProduct);
                break;
            case 4:
                cart(productCode, quantity, pricePerProduct);
                break;
            case 5:
                updateInventory(productCode, quantity, pricePerProduct);
                break;
            case 6:
                bill(productCode, quantity, pricePerProduct, promoCode);
                break;
            case 7:
                invoice(name, cnic, productCode, quantity, pricePerProduct);
                break;
            case 8:
                printf("Exiting Program! Thank you for shopping!\n");
                return 0;
            default:
                printf("Invalid Input! Try again.\n");
        }
    }
}

void information(char name[], char cnic[]) {
    printf("\nEnter Customer Details:\n");
    printf("Name: ");
    scanf(" %[^\n]", name);
    printf("CNIC (with hyphen): ");
    scanf(" %s", cnic);
}

void fillInventory(int productCode[], int quantity[], float pricePerProduct[]) {
    int i;
    printf("\nEnter number of products to add: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Code, Quantity, and Price per product: ");
        scanf("%d %d %f", &productCode[i], &quantity[i], &pricePerProduct[i]);
    }
    printf("Inventory filled successfully!\n");
}

void displayInventory(int productCode[], int quantity[], float pricePerProduct[]) {
    int i;
    printf("\nAvailable Items:\n");
    printf("Product Code | Quantity | Price Per Product\n");
    for (i = 0; i < n; i++) {
        printf("%d | %d | %.2f\n", productCode[i], quantity[i], pricePerProduct[i]);
    }
}

void cart(int productCode[], int quantity[], float pricePerProduct[]) {
    int code, qty, i, found = 0;
    printf("\nEnter the Product Code: ");
    scanf("%d", &code);
    for (i = 0; i < n; i++) {
        if (code == productCode[i]) {
            found = 1;
            g = i;
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (qty <= quantity[i]) {
                f = qty;
                printf("\nAdded to Cart:\n");
                printf("Product %d | Qty %d | Price %.2f | Total %.2f\n",
                       productCode[i], qty, pricePerProduct[i], qty * pricePerProduct[i]);
                quantity[i] -= qty;
            } else {
                printf("Insufficient Quantity in stock!\n");
            }
            break;
        }
    }
    if (!found)
        printf("Product %d not found in inventory!\n", code);
}

void updateInventory(int productCode[], int quantity[], float pricePerProduct[]) {
    int i;
    printf("\nUpdated Inventory:\n");
    printf("Product Code | Quantity | Price Per Product\n");
    for (i = 0; i < n; i++) {
        printf("%d | %d | %.2f\n", productCode[i], quantity[i], pricePerProduct[i]);
    }
}

void bill(int productCode[], int quantity[], float pricePerProduct[], char promoCode[]) {
    char promo[MAX];
    totalBill = pricePerProduct[g] * f;
    printf("\nYour Bill for Product %d is: %.2f\n", productCode[g], totalBill);
    printf("Enter Promo Code (if any): ");
    scanf(" %s", promo);
    if (strcmp(promo, "Eid2025") == 0) {
        ifFound = 1;
        discount = totalBill * 0.75;
        printf("Promo Applied! 25%% Discount Given.\n");
        printf("Discounted Total: %.2f\n", discount);
    } else {
        printf("Invalid or No Promo Code Applied.\n");
    }
}

void invoice(char name[], char cnic[], int productCode[], int quantity[], float pricePerProduct[]) {
    printf("\n--------------- INVOICE ---------------\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("---------------------------------------\n");
    printf("Product Code: %d\n", productCode[g]);
    printf("Quantity: %d\n", f);
    printf("Price per Product: %.2f\n", pricePerProduct[g]);
    printf("---------------------------------------\n");
    printf("Total Bill: %.2f\n", totalBill);
    if (ifFound)
        printf("Total after 25%% Discount: %.2f\n", discount);
    printf("---------------------------------------\n");
    printf("Thank You for Shopping at XYZ SuperMarket!\n");
}

