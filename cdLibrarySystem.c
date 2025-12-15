#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CD{
    char id[10];
    char artName[20];
    char genre[20];
    int tracks;
};

void add(struct CD *cd, int n){
    int i;
    for(i=0;i<n;i++){
        printf("ID\n");
        scanf("%s", cd[i].id);

        printf("ARTIST NAME\n");
        scanf("%s", cd[i].artName);

        printf("GENRE\n");
        scanf("%s", cd[i].genre);

        printf("TRACKS\n");
        scanf("%d", &cd[i].tracks);
    }
}

void removeCD(struct CD *cd, int *n, char remove[]){
    int i, j;
    for(i=0;i<*n;i++){
        if(strcmp(cd[i].id, remove) == 0){
            for(j=i; j<(*n)-1; j++){
                cd[j] = cd[j+1];
            }
            (*n)--;
            printf("\n%s REMOVED\n", remove);
            return;
        }
    }
    printf("\nNOT FOUND\n");
}

void search(struct CD *cd, int n, char search[]){
    int i, found = 0;
    for(i=0;i<n;i++){
        if(strcmp(cd[i].id, search) == 0){
            printf("\n%s FOUND\n", search);
             = 1;
        }
    }
    if(!flag){
        printf("\nNOT FOUND\n");
    }
}

void update(struct CD *cd, int n, char id1[], char artName1[], char genre1[], int tracks1){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(cd[i].id, id1) == 0){
            strcpy(cd[i].artName, artName1);
            strcpy(cd[i].genre, genre1);
            cd[i].tracks = tracks1;
            printf("UPDATED\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

void sortArtist(struct CD *cd, int n){
    int i, j;
    struct CD temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(strcmp(cd[j].artName, cd[j+1].artName) > 0){
                temp = cd[j];
                cd[j] = cd[j+1];
                cd[j+1] = temp;
            }
        }
    }
    printf("SORTED BY ARTIST NAME\n");
}

int main(){
    struct CD *cd;
    int n;

    printf("\nOf how many CDs data you have to enter\n");
    scanf("%d", &n);

    cd = malloc(n * sizeof(struct CD));

    int choice;

    while(1){
        printf("\nEnter\n1. ADD\n2. REMOVE\n3. SEARCH\n4. UPDATE\n5. TO SORT\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                add(cd, n);
                break;

            case 2: {
                char rem[20];
                printf("ID TO REMOVE:\n");
                scanf("%s", rem);
                removeCD(cd, &n, rem);
                break;
            }

            case 3: {
                char ser[20];
                printf("ID TO SEARCH:\n");
                scanf("%s", ser);
                search(cd, n, ser);
                break;
            }

            case 4: {
                char id1[10];
                char artName1[20];
                char genre1[20];
                int tracks1;

                printf("ID\n");
                scanf("%s", id1);

                printf("ARTIST NAME\n");
                scanf("%s", artName1);

                printf("GENRE\n");
                scanf("%s", genre1);

                printf("TRACKS\n");
                scanf("%d", &tracks1);

                update(cd, n, id1, artName1, genre1, tracks1);
                break;
            }

            case 5:
                sortArtist(cd, n);
                break;

            default:
                printf("INVALID CHOICE\n");
        }
    }

    free(cd);
    return 0;
}

