#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int i, arr[n];
	printf("\n========\n");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int count = 0;
	for(i=0;i<n;i++){
		if( (arr[i]>arr[i+1]) || i == n-1 ){
			count++;
		}
	}
	printf("COUNT of PEAK = %d\n", count);
	return 0;
}
