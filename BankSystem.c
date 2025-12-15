#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Personal {
    char name[20];
    char cnic[15];
    char phone[15];
};

struct BankAcc {
    char holder[20];
    int accNum;
    float bal;
    char type[20];
    struct Personal data;
};

void deposit(struct BankAcc *acc, float amount) {
    acc->bal += amount;
    printf("AFTER Deposit Card holder %s with Name %s Remained %.2f Balance\n", 
           acc->holder, acc->data.name, acc->bal);
}

void withdraw(struct BankAcc *acc, float amount) {
    if(acc->bal >= amount) {
        acc->bal -= amount;
        printf("AFTER Withdraw Card holder %s with Name %s Remained %.2f Balance\n", 
               acc->holder, acc->data.name, acc->bal);
    } else {
        printf("Insufficient Balance!\n");
    }
}

int main() {
    struct BankAcc acc;

    strcpy(acc.holder, "Fatima");
    acc.accNum = 4456;
    acc.bal = 50000.0;
    strcpy(acc.type, "Normal");

    strcpy(acc.data.name, "Mehmood");
    strcpy(acc.data.cnic, "42323213221");
    strcpy(acc.data.phone, "034214341");

    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);

    int choice;
    printf("Enter\n1. Deposit\n2. Withdraw\n");
    scanf("%d", &choice);

    if(choice == 1)
        deposit(&acc, amount);
    else if(choice == 2)
        withdraw(&acc, amount);
    else
        printf("Invalid Input. BYE!\n");

    return 0;
}

