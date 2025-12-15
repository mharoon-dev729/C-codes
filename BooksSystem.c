#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BOOK{
    char title[20];
    char author[20];
    int YOP;
    float price;
};

void addbook(struct BOOK *book, int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%s %s %d %f", book[i].title, book[i].author, &book[i].YOP, &book[i].price);
    }
}

void display(struct BOOK *book, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%s %s %d %.2f\n", book[i].title, book[i].author, book[i].YOP, book[i].price);
    }
}

char* search(struct BOOK *book, int n, char search[], int *found){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(book[i].title, search) == 0){
            *found = 1;
            return book[i].author;
        }
    }
    return NULL;
}

float avg(struct BOOK *book, int n){
    int i;
    float sum = 0;
    for(i=0;i<n;i++){
        sum += book[i].price;
    }
    float AVG = sum / n;
    return AVG;
}

void recursion(struct BOOK *book, int index, int n){
    if(index == n){
        return;
    }
    printf("%s %s %d %.2f\n",book[index].title, book[index].author, book[index].YOP, book[index].price);

    recursion(book, index + 1, n);
}

int main(){
    int n;
    scanf("%d", &n);

    struct BOOK *book = malloc(n * sizeof(struct BOOK));

    addbook(book, n);
    display(book, n);

    char searchh[20];
    printf("ENTER TITLE TO BE SEARCHED\n");
    scanf("%s", searchh);

    int found = 0;
    char *authorname = search(book, n, searchh, &found);

    if(found){
        printf("BOOK WITH TITLE %s IS WRITTEN BY %s\n", searchh, authorname);
    }
    else{
        printf("NOT FOUND!\n");
    }

    float average = avg(book, n);
    printf("AVERAGE IS %.2f\n", average);

    printf("\nRecursive Display:\n");
    recursion(book, 0, n);

    free(book);
    return 0;
}

