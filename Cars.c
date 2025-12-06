#include <stdio.h>
#include <string.h>

struct Car {
    char brand[30];
    int mileage;
    float rental_cost;
    int seats;
};

void bestCar(struct Car c[], int n, char *bestBrand, float *eff) {
    float best = -1;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        float e = c[i].mileage / c[i].rental_cost;
        if (e > best) {
            best = e;
            idx = i;
        }
    }

    strcpy(bestBrand, c[idx].brand);
    *eff = best;
}

int main() {
    struct Car c[5] = {
        {"Toyota Corolla", 16, 5000, 5},
        {"Honda City", 18, 5500, 5},
        {"Suzuki Alto", 22, 3500, 4},
        {"Kia Sportage", 12, 8000, 7},
        {"Hyundai Tucson", 14, 7500, 7}
    };

    char bestBrand[30];
    float eff;

    bestCar(c, 5, bestBrand, &eff);

    printf("Best Car: %s (Efficiency = %.2f)\n", bestBrand, eff);

    return 0;
}

