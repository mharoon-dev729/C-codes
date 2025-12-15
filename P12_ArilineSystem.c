#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assign(char ***chart, int rows, int seatsPR){
    int i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<seatsPR;j++){
            scanf("%s", chart[i][j]);
        }
    }
}

void search(char ***chart, int rows, int seatsPR, char name[]){
    int i, j, found = 0;
    for(i=0;i<rows;i++){
        for(j=0;j<seatsPR;j++){
            if(strcmp(chart[i][j], name) == 0){
                printf("%s is FOUND at row %d seat %d\n", chart[i][j], i, j);
                found = 1;
            }
        }
    }
    if(!found){
        printf("NOT FOUND!\n");
    }
}

void cancel(char ***chart, int rows, int seatsPR, char name2[]){
    int i, j, found = 0;
    for(i=0;i<rows;i++){
        for(j=0;j<seatsPR;j++){
            if(strcmp(chart[i][j], name2) == 0){
                strcpy(chart[i][j], "\0");
                printf("CANCELLED %s\n", name2);
                found = 1;
            }
        }
    }
    if(!found){
        printf("NOT FOUND!\n");
    }
}

int main(){
    int rows, seatsPR;
    scanf("%d %d", &rows, &seatsPR);

    char ***chart;
    chart = malloc(rows * sizeof(char**));

    int i, j;

    for(i=0;i<rows;i++){
        chart[i] = malloc(seatsPR * sizeof(char*));
        for(j=0;j<seatsPR;j++){
            chart[i][j] = malloc(30 * sizeof(char));
            strcpy(chart[i][j], "\0");
        }
    }

    // assigning
    assign(chart, rows, seatsPR);

    // searching
    char name[20];
    scanf("%s", name);
    search(chart, rows, seatsPR, name);

    // cancellation
    char name2[20];
    scanf("%s", name2);
    cancel(chart, rows, seatsPR, name2);

    // reallocation
    int new_rows = rows;
    int n;

    printf("WANT TO RESIZE THE CHART SIZE? 1 = Yes 2 = No\n");
    scanf("%d", &n);

    if(n == 1){
        scanf("%d", &new_rows);

        // shrinking
        if(new_rows < rows){
            for(i=new_rows; i<rows; i++){
                for(j=0;j<seatsPR;j++){
                    free(chart[i][j]);
                }
                free(chart[i]);
            }
            chart = realloc(chart, new_rows * sizeof(char**));
        }
        // expanding
        else if(new_rows > rows){
            chart = realloc(chart, new_rows * sizeof(char**));

            for(i=rows; i<new_rows; i++){
                chart[i] = malloc(seatsPR * sizeof(char*));
                for(j=0;j<seatsPR;j++){
                    chart[i][j] = malloc(30 * sizeof(char));
                    scanf("%s", chart[i][j]);
                }
            }
        }
    }

    // free memory
    for(i=0;i<new_rows;i++){
        for(j=0;j<seatsPR;j++){
            free(chart[i][j]);
        }
        free(chart[i]);
    }
    free(chart);

    return 0;
}

