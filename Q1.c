// ALL THE REASONINGS ARE WRITTEN IN WORD FILE

#include <stdio.h>
// recursive function (using GIVEN parameters)
float calculateRepayment(float loan, float interestRate, int years) {
    // BASE CASE
    if (years == 0 || loan <= 0) {
        return 0;
    }
    // fixed yearly installment
    float installment = 40000;  
    // extra yearly payment
    float extraPayment;
    printf("Enter extra payment for year %d: ", years);
    scanf("%f", &extraPayment);
    // subtracting installment and extra payment from loan
    loan -= (installment + extraPayment);
    // preventing negative remaining loan
    if (loan < 0) {
        loan = 0;
    }
    // applying interest on the remaining loan
    loan = loan + (loan * interestRate);
    // printing status of this year
    printf("\tYear %d: \tRemaining loan = %.2f\n", years, loan);
    // recursive call for the remaining years
    return installment + extraPayment + calculateRepayment(loan, interestRate, years - 1);
}
// FUNCTION main
int main() {
    float loan, interestRate;
    int years;
    // input
    printf("Enter loan amount: ");
    scanf("%f", &loan);
    printf("Enter interest rate in decimel (i.e 0.01 for 1%%): ");
    scanf("%f", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &years);
    printf("\t---Repayment Schedule---\n");
    float totalPaid = calculateRepayment(loan, interestRate, years);
    printf("Total paid over %d years = %.2f\n", years, totalPaid);

    return 0;
}

