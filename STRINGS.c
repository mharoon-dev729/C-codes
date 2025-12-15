#include <stdio.h>
#include <string.h>

/* Global arrays */
char *ones[] = {
    "Zero", "One", "Two", "Three", "Four",
    "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

char *tens[] = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

/* Global result buffer */
char result[200] = "";

/* Recursive function */
char* numToWords(int num)
{
    if (num == 0)
        return result;

    if (num >= 1000) {
        numToWords(num / 1000);
        strcat(result, " Thousand ");
        numToWords(num % 1000);
    }
    else if (num >= 100) {
        numToWords(num / 100);
        strcat(result, " Hundred ");
        numToWords(num % 100);
    }
    else if (num >= 20) {
        strcat(result, tens[num / 10]);
        strcat(result, " ");
        numToWords(num % 10);
    }
    else if (num > 0) {
        strcat(result, ones[num]);
        strcat(result, " ");
    }

    return result;
}

/* Driver code */
int main()
{
    int num;
    printf("Enter Number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Zero");
    } else {
        printf("%s", numToWords(num));
    }

    return 0;
}
