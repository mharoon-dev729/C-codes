#include <stdio.h>
#include <stdbool.h>

void updateStatus(int grid[][3]) {
    int row, col, flagNum, setOrClear;
    printf("\nEnter coordinates of sector: ");
    scanf("%d %d", &row, &col);
    
    printf("\n1. Power Status (1 = ON, 0 = OFF) \n2. Overload Warning (1 = Overloaded, 0 = Normal) \n3. Maintenance Required (1 = Yes, 0 = No) \nChoose Flag :");
    scanf("%d", &flagNum);
    
    printf("\nEnter 1 to SET or 0 to CLEAR: ");
    scanf("%d", &setOrClear);
    
    int bitIndex = flagNum - 1;
    
    if(setOrClear == 1) {
        grid[row][col] |= (1 << bitIndex);
    } else {
        grid[row][col] &= ~(1 << bitIndex);
    }
    
    printf("\nUpdated value at (%d, %d): %d\n", row, col, grid[row][col]);	
}

void checkStatus(int grid[][3]) {
    int row, col, k;
    bool power = false, overload = false, maintenance = false;
    
    printf("\nEnter coordinates of sector: ");
    scanf("%d %d", &row, &col);
    
    for(k = 3; k >= 0; k--) {
        int bit = (grid[row][col] >> k) & 1;
        if(k == 0 && bit == 1) power = true;
        else if(k == 1 && bit == 1) overload = true;
        else if(k == 2 && bit == 1) maintenance = true;
    }
    
    power ? printf("Power Status : ON") : printf("\nPower Status : OFF");
    overload ? printf("\nOverload Status : Overloaded") : printf("\nOverload Status : Normal");
    maintenance ? printf("\nMaintenance Required : YES\n") : printf("\nMaintenance Required : NO\n");
}

void diagnostics(int grid[][3]) {
    int i, j, k, overloadCount = 0, maintenanceCount = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            for(k = 3; k >= 0; k--) {
                int bit = (grid[i][j] >> k) & 1;
                if(k == 1 && bit == 1) overloadCount++;
                if(k == 2 && bit == 1) maintenanceCount++;
            }
        }
    }
    printf("\n%d Sectors are currently overloaded", overloadCount);
    printf("\n%d Sectors require maintenance\n", maintenanceCount);
}

void main() {
    int grid[3][3] = {{1,2,3}, {3,4,8}, {9,1,7}};
    
    int i, j, choice;
    
    printf("Sector's Grid: \n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d  ", grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\n1. Update Sector Status \n2. Check Sector Status \n3. Run Diagnostics \n4. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                updateStatus(grid);
                break;
            case 2:
                checkStatus(grid);
                break;
            case 3:
                diagnostics(grid);
                break;
            case 4:
                printf("\nExiting!");
                break;
            default:
                printf("\nInvalid Choice!");
        }
    } while(choice != 4);
}

