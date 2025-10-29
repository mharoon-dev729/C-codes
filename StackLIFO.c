#include <stdio.h>

void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int *top);
void display(int stack[], int *top);

int main() {
    int stack[100];
    int top = -1;
    int maxSize = 100;
    int choice;
 
    while (1) {
         printf("================================\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter choice: \n");
        printf("================================\n");
        printf("================================\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(stack, &top, maxSize); break;
            case 2: pop(stack, &top); break;
            case 3: peek(stack, &top); break;
            case 4: display(stack, &top); break;
            case 5: return 0;
            default: printf("Invalid input\n");
        }
    }
}

void push(int stack[], int *top, int maxSize) {
    int val;
    if (*top == maxSize - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        (*top)++;
        stack[*top] = val;
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Removed: %d\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top: %d\n", stack[*top]);
    }
}

void display(int stack[], int *top) {
	int i;
    if (*top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = *top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

