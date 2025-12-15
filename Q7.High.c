#include <stdio.h>

int main(){
    int trafficLog[15][4];
    float sum=0.0;
    for(int i=0; i<15; i++){
        for(int j=0; j<4; j++){
            scanf("%d", &trafficLog[i][j]);
        }
        sum += trafficLog[i][2];
    }
    float avgData = sum/15;
    
    for(int i=0; i<15; i++){
        for(int j=0; j<4; j++){
            printf("|%5d|", trafficLog[i][j]);
        }
        printf("\n");
    }
    
    printf("\nAverage Data: %.2f", avgData);
    printf("\n\nHigh Risk Rows: \n");
    for(int i=0; i<15; i++){
        if(trafficLog[i][2]>avgData && trafficLog[i][3]>7){
            for(int j=0; j<4; j++){
                printf("|%5d|", trafficLog[i][j]);
            }
            printf("\n");
        }
    }
    
    for(int i=0; i<15; i++){
        for(int j=i+1; j<15; j++){
            if(trafficLog[i][3] < trafficLog[j][3]){
                for(int k=0; k<4; k++){
                    int temp = trafficLog[i][k];
                    trafficLog[i][k] = trafficLog[j][k];
                    trafficLog[j][k] = temp;
                }
            }
        }
    }
    
    printf("\n\nSorted By ThreatLevel: \n");
    for(int i=0; i<15; i++){
        for(int j=0; j<4; j++){
            printf("|%5d|", trafficLog[i][j]);
        }
        printf("\n");
    }
}
