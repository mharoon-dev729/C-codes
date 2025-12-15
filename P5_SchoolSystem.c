#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    char ***students = malloc(n1 * sizeof(char**));

    int i, j;
    for(i = 0; i < n1; i++){
        students[i] = malloc(n2 * sizeof(char*));
        for(j = 0; j < n2; j++){
            students[i][j] = malloc(50 * sizeof(char)); // string size
        }
    }
	//assign
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            scanf("%s", students[i][j]);
        }
    }
	//free
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            free(students[i][j]);
        }
        free(students[i]);
    }
    free(students);

    return 0;
}

