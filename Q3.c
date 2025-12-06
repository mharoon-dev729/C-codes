// ALL THE REASONINGS ARE WRITTEN IN WORD FILE

#include <stdio.h>
#include <string.h>
// structure
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};
// FUNCTION to display all employees
void displayEmployees(struct Employee emp[], int n) {
    printf("\n------------------------------------------------------------\n");
    printf(" ID\t\tName\t\tDesignation\t\tSalary\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t%-10s\t%-15s\t%.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].designation,
               emp[i].salary);
    }
    printf("------------------------------------------------------------\n");
}
// FUNCTION to find employee with highest salary
void findHighestSalary(struct Employee emp[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > emp[maxIndex].salary) {
            maxIndex = i;
        }
    }
    printf("\nEmployee With Highest Salary:\n");
    printf("ID: %d\n", emp[maxIndex].id);
    printf("Name: %s\n", emp[maxIndex].name);
    printf("Designation: %s\n", emp[maxIndex].designation);
    printf("Salary: %.2f\n", emp[maxIndex].salary);
}
// FUNCTION to search employee
void searchEmployee(struct Employee emp[], int n) {
    int choice;
    printf("\nSearch Employee By:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        int searchID;
        printf("Enter ID to search: ");
        scanf("%d", &searchID);
        for (int i = 0; i < n; i++) {
            if (emp[i].id == searchID) {
                printf("\nEmployee Found:\n");
                printf("ID: %d\n", emp[i].id);
                printf("Name: %s\n", emp[i].name);
                printf("Designation: %s\n", emp[i].designation);
                printf("Salary: %.2f\n", emp[i].salary);
                return;
            }
        }
        printf("Employee not found.\n");
    } else if (choice == 2) {
        char searchName[50];
        printf("Enter Name to search: ");
        scanf("%s", searchName);
        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].name, searchName) == 0) {
                printf("\nEmployee Found:\n");
                printf("ID: %d\n", emp[i].id);
                printf("Name: %s\n", emp[i].name);
                printf("Designation: %s\n", emp[i].designation);
                printf("Salary: %.2f\n", emp[i].salary);
                return;
            }
        }
        printf("Employee not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
}
// FUNCTION main
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    // taking input for n number of employees
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details of Employee %d ---\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    // calling function to display all employees
    displayEmployees(emp, n);
    // calling function to show employee with highest salary
    findHighestSalary(emp, n);
    // calling function to search functionality
    searchEmployee(emp, n);
    return 0;
}

