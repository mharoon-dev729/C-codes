#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Package{
	char id[20];
	int weight;
	int regioncode;
	int priority;
};

void add(struct Package **package, int n, int m){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%s %d %d %d", package[i][j].id, &package[i][j].weight, &package[i][j].regioncode, &package[i][j].priority);
		}
	}
}

void sort(struct Package **package, int n, int m){
	int i, j;
	char temp[20];
	int x, y, z;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if( strcmp(package[i][j].id, package[i][j+1].id) > 0 ){
				//swaping id
				strcpy(temp, package[i][j].id);
				strcpy(package[i][j].id, package[i][j+1].id);
				strcpy(package[i][j+1].id, temp);
				//swaping weight
				x = package[i][j].weight;
				package[i][j].weight = package[i][j+1].weight;
				package[i][j+1].weight = x; 
				//regioncode
				y = package[i][j].regioncode;
				package[i][j].regioncode = package[i][j+1].regioncode;
				package[i][j+1].regioncode = y; 
				//swaping priority
				z = package[i][j].regioncode;
				package[i][j].regioncode = package[i][j+1].regioncode;
				package[i][j+1].regioncode = z;
			}
		}
	}
}

void search(struct Package **package, int n, int m, char ser[]){
	int i, j;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if( strcmp(package[i][j].id, ser)  == 0 ){
					printf("FOUND\n");
				}
		}
	}
}


int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	struct Package **package;
	
	package = malloc(N * sizeof(struct Package*));
	int i, j;
	for(i=0;i<N;i++){
		package[i] = malloc(M * sizeof(struct Package));
	}
	
	//add
	add(package, N, M);
	//sort
	sort(package, N, M);
	//search
	char ser[20];
	scanf("%s", ser);
	search(package, N, M, ser);
	
	//reallocation
	printf("1 for yes 0 for for no");
	int n, N1;
	scanf("%d", &n);
	if(n==1){
		scanf("%d", &N1);
		if(N1<N){
			package = realloc(package, N1 * sizeof(struct Package*));
			//freeing
			for(i=N1;i<N;i++){
				free(package[i]);
			}
		}
		else if(N1>N){
			package = realloc(package, N1 * sizeof(struct Package*));
			//assigning
			for(i=N;i<N1;i++){
				for(j=0;j<M;j++){
					scanf("%s %d %d %d", package[i][j].id, &package[i][j].weight, &package[i][j].regioncode, &package[i][j].priority);
				}
			}
			
		}
	}

	//freeing memory
	for(i=0;i<N1;i++){
		free(package[i]);
	}
	free(package);

	return 0;
}
