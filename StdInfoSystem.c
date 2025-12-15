#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct department{
	char departname[20];
	int buildnum;
};
struct student{
	char name[20];
	char roll[10];
	float cgpa;
	struct department depart;
};
void input(struct student *std, int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%s %s %f %s %d", std[i].name, std[i].roll, &std[i].cgpa, std[i].depart.departname, &std[i].depart.buildnum);
	}
}
void display(struct student *std, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s %s %f %s %d", std[i].name, std[i].roll, std[i].cgpa, std[i].depart.departname, std[i].depart.buildnum);
	}
}
void probation(struct student *std, int n){
	int i;
	for(i=0;i<n;i++){
		if(std[i].cgpa < 2.0){
			printf("%s STUDENT FROM %s DEPARTMENT HAS LESS THAN 2.0 CGPA\n", std[i].name, std[i].depart.departname);
		}
	}
}
int main(){
	struct student *std;
	int n;
	scanf("%d", &n);
	
	std = malloc(n * sizeof(struct student));
	
	input(std, n);
	display(std, n);
	probation(std, n);
	
	free(std);
	return 0;
}
