#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Train {
    int Train_no;
    char Source[50];
    char Destination[50];
    char DepartureTime[10];
    int SeatsAvailable;      // 0–500
    float TicketPrice;       // positive
};

int isUnique(struct Train *arr, int count, int tno) {
    for (int i = 0; i < count; i++) {
        if (arr[i].Train_no == tno)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number of trains: ");
    scanf("%d", &n);

    struct Train *T = (struct Train*)malloc(n * sizeof(struct Train));

    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details for Train %d ---\n", i + 1);

        // Train number (unique)
        int num;
        while (1) {
            printf("Train Number: ");
            scanf("%d", &num);
            if (isUnique(T, i, num)) break;
            printf("Error: Train number must be UNIQUE!\n");
        }
        T[i].Train_no = num;

        // Strings
        printf("Source: ");
        scanf("%s", T[i].Source);

        printf("Destination: ");
        scanf("%s", T[i].Destination);

        printf("Departure Time (HH:MM): ");
        scanf("%s", T[i].DepartureTime);

        // Seats validation
        do {
            printf("Seats Available (0–500): ");
            scanf("%d", &T[i].SeatsAvailable);
            if (T[i].SeatsAvailable < 0 || T[i].SeatsAvailable > 500)
                printf("Invalid seats! Try again.\n");
        } while (T[i].SeatsAvailable < 0 || T[i].SeatsAvailable > 500);

        // Ticket positive
        do {
            printf("Ticket Price (positive): ");
            scanf("%f", &T[i].TicketPrice);
            if (T[i].TicketPrice <= 0)
                printf("Price must be positive!\n");
        } while (T[i].TicketPrice <= 0);
    }

    // ================================
    //       FIND REQUIRED OUTPUTS
    // ================================

    int maxSeatsIndex = 0;
    int maxPriceIndex = 0;
    float sumPrice = 0;

    for (int i = 0; i < n; i++) {
        if (T[i].SeatsAvailable > T[maxSeatsIndex].SeatsAvailable)
            maxSeatsIndex = i;

        if (T[i].TicketPrice > T[maxPriceIndex].TicketPrice)
            maxPriceIndex = i;

        sumPrice += T[i].TicketPrice;
    }

    float avgPrice = sumPrice / n;

    // ================================
    //           DISPLAY RESULTS
    // ================================
    printf("\n\n===== RESULTS =====\n");

    printf("\nTrain with MAX seats available:\n");
    printf("Train No: %d | From %s to %s | Seats: %d | Price: %.2f\n",
           T[maxSeatsIndex].Train_no,
           T[maxSeatsIndex].Source,
           T[maxSeatsIndex].Destination,
           T[maxSeatsIndex].SeatsAvailable,
           T[maxSeatsIndex].TicketPrice);

    printf("\nTrain with HIGHEST ticket price:\n");
    printf("Train No: %d | From %s to %s | Price: %.2f | Seats: %d\n",
           T[maxPriceIndex].Train_no,
           T[maxPriceIndex].Source,
           T[maxPriceIndex].Destination,
           T[maxPriceIndex].TicketPrice,
           T[maxPriceIndex].SeatsAvailable);

    printf("\nAverage Ticket Price: %.2f\n", avgPrice);

    // ================================
    //               SEARCH
    // ================================
    char src[50], dst[50];
    printf("\nEnter Source to search: ");
    scanf("%s", src);
    printf("Enter Destination to search: ");
    scanf("%s", dst);

    printf("\nMatching Trains:\n");
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(T[i].Source, src) == 0 && strcmp(T[i].Destination, dst) == 0) {
            found = 1;
            printf("Train No: %d | %s -> %s | Time: %s | Seats: %d | Price: %.2f\n",
                   T[i].Train_no,
                   T[i].Source,
                   T[i].Destination,
                   T[i].DepartureTime,
                   T[i].SeatsAvailable,
                   T[i].TicketPrice);
        }
    }

    if (!found)
        printf("No trains found for this route.\n");

    free(T);
    return 0;
}

