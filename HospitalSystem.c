#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct patient{
    int id;
    char name[30];
    int age;
    char disease[30];    
    int admittedDays;
    float perDayscharges;
    float bill;
};

void inputPatients(struct patient *Patient, int numOfPatient){
    int i, x, y;
    for(i=0;i<numOfPatient;i++){
        
        printf("\nEnter ID\n");
        scanf("%d", &Patient[i].id);

        printf("\nEnter Name\n");
        scanf("%s", Patient[i].name);
        
        do{
            printf("\nEnter Age\n");
            scanf("%d", &x);
        } while (x<=0);
        Patient[i].age = x;
        
        printf("\nEnter Disease\n");
        scanf("%s", Patient[i].disease);
        
        do{
            printf("\nEnter Admitted Days\n");
            scanf("%d", &y);
        } while (y<1);
        Patient[i].admittedDays = y;

        printf("\nEnter Charges Per Day\n");
        scanf("%f", &Patient[i].perDayscharges);
    }
}

float* calculatebill(struct patient *Patient, int numOfPatient){
    int i;
    		float toStore[1000]; 

    for(i=0;i<numOfPatient;i++){
        
        Patient[i].bill = Patient[i].admittedDays * Patient[i].perDayscharges;
        
        if(Patient[i].admittedDays > 10){
            Patient[i].bill -= Patient[i].bill * 0.1;

            if(Patient[i].age > 60){
                Patient[i].bill -= Patient[i].bill * 0.05;
            }
        }

        toStore[i] = Patient[i].bill;
    }
    return toStore;
}

void search(struct patient *Patient, char name[], int numOfPatient){
    int i, found = 0;
    for(i=0;i<numOfPatient;i++){
        if(strcmp(Patient[i].name, name) == 0){
            found = 1;
            printf("\n%s | %s | %.2f\n", 
                Patient[i].name, 
                Patient[i].disease,
                Patient[i].bill);
            break;
        }
    }
    if(!found){
        printf("%s not found\n", name);
    }
}

int main(){
    int numOfPatient;
    scanf("%d", &numOfPatient);

    struct patient *Patient;
    Patient = malloc(numOfPatient * sizeof(struct patient));
    
    inputPatients(Patient, numOfPatient);
    
    float *BILL = calculatebill(Patient, numOfPatient);
    
    int i;
    for(i=0;i<numOfPatient;i++){
        printf("\n%s has to Pay %.2f\n", Patient[i].name, BILL[i]);
    }
    
    char searchName[30];
    printf("Enter Name to search\n");
    scanf("%s", searchName);
    
    search(Patient, searchName, numOfPatient);
    
    free(Patient);
    return 0;
}

