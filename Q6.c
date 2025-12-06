#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "members.dat"
// structure
typedef struct {
    int studentID;            
    char fullName[100];       
    char batch[20];           
    char membershipType[10];  
    char regDate[15];         
    char dob[15];             
    char interest[10];        
} Student;
// dynamic array
Student *db = NULL;     
int dbSize = 0;
// loading data from members.dat file
void loadDatabase() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("Error ---- > No existing database found. Starting fresh\n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    dbSize = size / sizeof(Student);
    db = (Student*) malloc(dbSize * sizeof(Student));
    fread(db, sizeof(Student), dbSize, fp);
    fclose(fp);
    printf("%d records loaded from file\n", dbSize);
}
// to save data in a file
void saveDatabase() {
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) {
        printf("Error ---- > opening file for saving\n");
        return;
    }
    fwrite(db, sizeof(Student), dbSize, fp);
    fclose(fp);
    printf("Database saved successfully\n");
}

// checking duplicate ids
int idExists(int id) {
	int i;
    for (i = 0; i < dbSize; i++)
        if (db[i].studentID == id)
            return 1;
    return 0;
}
// to add students
void addStudent() {
    Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.studentID);
    if (idExists(s.studentID)) {
        printf("Error ---- > Student ID already exists!\n");
        return;
    }
    printf("Full Name: ");
    scanf(" %[^\n]", s.fullName);
    printf("Batch (CS/SE/Cyber/AI): ");
    scanf("%s", s.batch);
    printf("Membership Type (IEEE/ACM): ");
    scanf("%s", s.membershipType);
    printf("Registration Date (YYYY-MM-DD): ");
    scanf("%s", s.regDate);
    printf("DOB (YYYY-MM-DD): ");
    scanf("%s", s.dob);
    printf("Interest (IEEE/ACM/Both): ");
    scanf("%s", s.interest);
    db = realloc(db, (dbSize + 1) * sizeof(Student));
    db[dbSize++] = s;
    saveDatabase();
    printf("Student added successfully\n");
}
// to update students data
void updateStudent() {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
	int i;
    for (i = 0; i < dbSize; i++) {
        if (db[i].studentID == id) {
            printf("Update Batch: ");
            scanf("%s", db[i].batch);

            printf("Update Membership Type: ");
            scanf("%s", db[i].membershipType);

            saveDatabase();
            printf("Record updated\n");
            return;
        }
    }
    printf("Student not found\n");
}
// to delete students data from the file
void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    int found = 0, i;
    for (i = 0; i < dbSize; i++) {
        if (db[i].studentID == id) {
            found = 1;
			int j;
            for (j = i; j < dbSize - 1; j++)
                db[j] = db[j + 1];
            dbSize--;
            db = realloc(db, dbSize * sizeof(Student));
            saveDatabase();
            printf("Record deleted\n");
            return;
        }
    }
    if (!found)
        printf("Student not found\n");
}
// to display all the registered students
void displayAll() {
    if (dbSize == 0) {
        printf("No records\n");
        return;
    }
	int i;
    for (i = 0; i < dbSize; i++) {
        printf("\nID: %d\nName: %s\nBatch: %s\nMembership: %s\nReg Date: %s\nDOB: %s\nInterest: %s\n",
               db[i].studentID, db[i].fullName, db[i].batch,
               db[i].membershipType, db[i].regDate, db[i].dob,
               db[i].interest);
    }
}
// batch wise and interest wise report
void batchReport() {
    char batch[20];
    char type[10];
    printf("Enter batch (CS/SE/Cyber/AI): ");
    scanf("%s", batch);
    printf("Membership Type (IEEE/ACM/Both): ");
    scanf("%s", type);
    printf("\n--- Report ---\n");
	int i;
    for (i = 0; i < dbSize; i++) {
        if (strcmp(db[i].batch, batch) == 0 &&
            strcmp(db[i].interest, type) == 0)
        {
            printf("ID: %d | %s\n", db[i].studentID, db[i].fullName);
        }
    }
}
// FUNCTION main
int main() {
    loadDatabase();
    int choice;
    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. View All\n");
        printf("5. Batch Report\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: addStudent(); break;
        case 2: updateStudent(); break;
        case 3: deleteStudent(); break;
        case 4: displayAll(); break;
        case 5: batchReport(); break;
        case 6: saveDatabase(); exit(0);
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

