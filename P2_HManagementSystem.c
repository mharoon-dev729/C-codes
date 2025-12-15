#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char id[10];
    char name[20];
    char disease[20];
    int age;
};

// Add patients
void add(struct Patient **patient, int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("Enter ID Name Disease Age for patient [%d][%d]: ", i, j);
            scanf("%s %s %s %d", patient[i][j].id, patient[i][j].name, patient[i][j].disease, &patient[i][j].age);
        }
    }
}

// Remove patient by ID and clear the slot
void removePatient(struct Patient **patient, int row, int col, char removeid[]){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(strcmp(patient[i][j].id, removeid) == 0){
            	
				patient[i][j].id[0] = '\0';
				patient[i][j].name[0] = '\0';
                patient[i][j].disease[0] = '\0';
                patient[i][j].age = 0;

                printf("Patient with ID %s removed\n", removeid);
                return; 
            }
        }
    }
    printf("Patient with ID %s not found\n", removeid);
}

void status(struct Patient **patient, int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if( strcmp(patient[i][j].id, "\0") != 0 ){
				printf("Bed %d of Ward %d is occupied by %s\n", i+1, j+1, patient[i][j].name);
			}
			else{
				printf("Bed %d of Ward %d is empty\n", i+1, j+1);
			}
		}
	}
}

int main(){
    struct Patient **patient;
    int row, col;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    
    int i, j;
    // Allocate 2D array
    patient = malloc(row * sizeof(struct Patient*));
    for(i = 0; i < row; i++){
        patient[i] = malloc(col * sizeof(struct Patient));
        // Initialize all slots as empty
        for(j = 0; j < col; j++){
            patient[i][j].id[0] = '\0';
            patient[i][j].name[0] = '\0';
            patient[i][j].disease[0] = '\0';
            patient[i][j].age = 0;
        }
    }
    
    // Calling Add patients
    add(patient, row, col);
    
    // Calling Remove patient
    char removeid[20];
    printf("Enter ID to remove: ");
    scanf("%s", removeid);
    removePatient(patient, row, col, removeid);

    // Calling Print current status
	status(patient, row, col);

    // Free memory
    for(i = 0; i < row; i++){
        free(patient[i]);
    }
    free(patient);

    return 0;
}

