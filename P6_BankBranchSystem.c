#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Branch{
	char name[20];
	int numOfSer;
	char **services;
};

void search(struct Branch *branch, int n, char ser[]){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<branch[i].numOfSer;j++){
			if( strcmp(branch[i].services[j], ser) == 0 ){
				printf("FOUND!!!!!!!!!");
				return;
			}
		}
	}
}

int main(){
	struct Branch *branch;
	int n;
	scanf("%d", &n);
	
	branch = malloc(n * sizeof(struct Branch));
	int i, j;
	for(i=0;i<n;i++){
		scanf("%s &d", branch[i].name, &branch[i].numOfSer);
		
		branch[i].services = malloc(branch[i].numOfSer * sizeof(char*));
		for(j=0;j<branch[i].numOfSer;j++){
			branch[i].services[j] = malloc(30 * sizeof(char));
			scanf("%s", branch[i].services[j]);
		}
	}
	
	char ser[20];
	scanf("%s", ser);
	search(branch, n, ser);
	
	
	return 0;
}
