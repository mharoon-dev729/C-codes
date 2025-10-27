#include<stdio.h>

int findSum(int arr[], int size);

int main(){
    int size, i, totalSum;

    printf("Enter the number of elements size:\n");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size. Must be greater than 0.\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d integer values:\n", size);
    for(i = 0; i < size; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    totalSum = findSum(arr, size);
    printf("The sum of all elements is: %d\n", totalSum);

    return 0;
}

int findSum(int arr[], int size){
    int i;
    int sum = 0;

    for(i = 0; i < size; i++){
        sum += arr[i];
    }
    
    return sum;
}
