#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

struct patient{
	int id;
	char name[30];
	char disease[20];
};

struct room{
	int roomNum;
	int totalBeds;
	int occupiedBeds;
	struct patient *Patient;
};

struct cell{
	char type[10];
	struct room *Room;
};

void add(struct room *Room, int row, int col){
	//FILLING ROOM GRID
	int i, j, k;

	//n = number of patients per room
	scanf("%d", &n);

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){

			// allocate memory for room patient array
			Room[i*col + j].Patient = malloc(n * sizeof(struct patient));

			scanf("%d %d %d", &Room[i*col + j].roomNum, &Room[i*col + j].totalBeds, &Room[i*col + j].occupiedBeds);

			//FILLING PATIENT INFO
			for(k=0;k<n;k++){
				scanf("%d %s %s", &Room[i*col + j].Patient[k].id, Room[i*col + j].Patient[k].name, Room[i*col + j].Patient[k].disease);
			}
		}
	}
}

void diseaseSearch(struct room *Room, int row, int col, char search[]){
	int i, j, k;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			for(k=0;k<n;k++){
				if( strcmp(Room[i*col + j].Patient[k].disease, search) == 0){
					printf("%d %s %d\n", Room[i*col + j].roomNum, Room[i*col + j].Patient[k].name, Room[i*col + j].Patient[k].id);
				}
			}
		}
	}
}

void gridSummary(struct room *Room, int row, int col){
	int i, j, k;
	int totalRooms = 0;
	int totalPatients = 0;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(Room[i*col + j].totalBeds > 0){
				totalRooms++;
				totalPatients += Room[i*col + j].occupiedBeds;
			}
		}
	}

	printf("Total Rooms: %d\n", totalRooms);
	printf("Total Patients: %d\n", totalPatients);
}


int main(){
	int row, col;
	scanf("%d %d", &row, &col);

	struct cell **grid;
	grid = malloc(row * sizeof(struct cell*));

	int i;
	for(i=0;i<row;i++){
		grid[i] = malloc(col * sizeof(struct cell));
	}
	
	//Declaring Room
	struct room *Room = malloc(row * col * sizeof(struct room));

	int choice;
	printf("\n1. ROOM\n2. EMPTY\n");
	scanf("%d", &choice);

	if(choice==1){
		//CALLING add
		add(Room, row, col);
	}

	char search[20];
	scanf("%s", search);

	//CALLING diseaseSearch
	diseaseSearch(Room, row, col, search);

	//CALLING gridSummary
	gridSummary(Room, row, col);

	//Freeing memory
	for(i=0;i<row;i++){
		free(grid[i]);
	}
	free(grid);

	//Freeing memory
	for(i=0;i<row*col;i++){
		free(Room[i].Patient);
	}

	free(Room);

	return 0;
}

