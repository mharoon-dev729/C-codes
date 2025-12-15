#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cinema{
	char screenName[20];
	int numofscr;
	char **movies;
};

void serviceFinder(struct Cinema *cinema, int numOfmovies, char search[]){
	int i, j;
	int found = 0; 	//to check if movie is found
	for(i=0;i<numOfmovies;i++){
		for(j=0;j<cinema[i].numofscr;j++){
			if(!strcmp(cinema[i].movies[j], search)){
				printf("FOUND in %s\n", cinema[i].screenName);
				found = 1;
			}
		}
	}
	if(!found){
		printf("NOT FOUND!\n");
	}
}

int main(){
	int numOfmovies;
	scanf("%d", &numOfmovies);
	struct Cinema *cinema;
	
	cinema = malloc(numOfmovies * sizeof(struct Cinema));
	int i, j;
	for(i=0;i<numOfmovies;i++){
		scanf("%s", cinema[i].screenName);
		scanf("%d", &cinema[i].numofscr);
		
		cinema[i].movies = malloc(cinema[i].numofscr * sizeof(char*));
		for(j=0;j<cinema[i].numofscr;j++){
			cinema[i].movies[j] = malloc(100 * sizeof(char));
			scanf("%s", cinema[i].movies[j]);
		}
	}
	
	char search[20];
	scanf("%s", search);
	
	serviceFinder(cinema, numOfmovies, search);
	
	// free memory
	for(i=0;i<numOfmovies;i++){
		for(j=0;j<cinema[i].numofscr;j++){
			free(cinema[i].movies[j]);
		}
		free(cinema[i].movies);
	}
	free(cinema);
	return 0;
}

