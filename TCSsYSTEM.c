#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char str[]);
char toggleBits(char ch);

int main() {
    int choice;
    char message[1000];

    while (1) {
        printf("\n---------------------------\n");
        printf("   TCS Message Encoder Tool  \n");
        printf("=============================\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("\nEnter message to encode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            encodeMessage(message);
        } 
        else if (choice == 2) {
            printf("\nEnter message to decode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            decodeMessage(message);
        } 
        else if (choice == 3) {
            printf("\nExiting... Goodbye!\n");
            break;
        } 
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

void reverseString(char str[]) {
    int len = strlen(str);
    int i;
	for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char toggleBits(char ch) {
    ch ^= (1 << 1);
    ch ^= (1 << 4);
    return ch;
}

void encodeMessage(char message[]) {
    reverseString(message);
    int i;
    for (i = 0; message[i] != '\0'; i++)
        message[i] = toggleBits(message[i]);
    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    int i;
	for (i = 0; message[i] != '\0'; i++)
        message[i] = toggleBits(message[i]);
    reverseString(message);
    printf("\nDecoded Message: %s\n", message);
}

