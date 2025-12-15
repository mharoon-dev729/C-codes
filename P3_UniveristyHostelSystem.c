#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char id[10];
    char name[20];
};

struct Room{
    int roomNum;
    int floor;
    struct Student *student;
};

void assign(struct Room **room, int floor, int roomOfFloor, int numOfStudent){
    int i, j, k;

    for(i=0;i<floor;i++){
        for(j=0;j<roomOfFloor;j++){
            scanf("%d %d", &room[i][j].roomNum, &room[i][j].floor);
            for(k=0;k<numOfStudent;k++){
                scanf("%s %s", room[i][j].student[k].id, room[i][j].student[k].name);
            }
        }
    }
}

void vacate(struct Room **room, int floor, int roomOfFloor){
    int i, j;

    for(i=0;i<floor;i++){
        for(j=0;j<roomOfFloor;j++){
            if(room[i][j].roomNum == 0){
                printf("Room Number %d of floor %d is empty/vacate room\n", room[i][j].roomNum, room[i][j].floor);
            }
        }
    }
}

int countbyrecursion(struct Room **room, int floor, int roomOfFloor, int i, int j){

    // Base case: last floor crossed
    if(i >= floor)
        return 0;

    // Count current room
    int count = (room[i][j].roomNum == 0) ? 1 : 0;

    // Move to next cell
    int nextFloor = i;
    int nextRoom = j + 1;

    if(nextRoom >= roomOfFloor){
        nextRoom = 0;
        nextFloor++;
    }
    return count + countbyrecursion(room, floor, roomOfFloor, nextFloor, nextRoom);
}


int main(){

    struct Room **room;
    int floor, roomOfFloor;

    printf("Enter floors and rooms per floor: ");
    scanf("%d %d", &floor, &roomOfFloor);

    room = malloc(floor * sizeof(struct Room*));

    int i, j;

    for(i=0;i<floor;i++){
        room[i] = malloc(roomOfFloor * sizeof(struct Room));
    }

    // DMA for student per room
    int numOfStudent;
    printf("Enter number of students per room: ");
    scanf("%d", &numOfStudent);

    for(i=0;i<floor;i++){
        for(j=0;j<roomOfFloor;j++){
            room[i][j].student = malloc(numOfStudent * sizeof(struct Student));
            room[i][j].roomNum = 0;   // initially empty
            room[i][j].floor = i + 1; // default
        }
    }

    assign(room, floor, roomOfFloor, numOfStudent);

    vacate(room, floor, roomOfFloor);

    // Recursion
		int count = countbyrecursion(room, floor, roomOfFloor, 0, 0);
		printf("Empty rooms = %d\n", count);


    // Free memory
    for(i=0;i<floor;i++){
        for(j=0;j<roomOfFloor;j++){
            free(room[i][j].student);
        }
        free(room[i]);
    }
    free(room);

    return 0;
}

