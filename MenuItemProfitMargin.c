#include <stdio.h>
#include <string.h>

struct MenuItem {
    char dish_name[30];
    float selling_price;
    float ingredient_cost;
    int preparation_time;
};

void best(struct MenuItem m[], int n, char *bestDish, float *margin) {
    float bestM = -1;
    int idx = 0, i;

    for (i = 0; i < n; i++) {
        float mg = (m[i].selling_price - m[i].ingredient_cost) /
                   m[i].ingredient_cost;

        if (mg > bestM) {
            bestM = mg;
            idx = i;
        }
    }
    
    strcpy(bestDish, m[idx].dish_name);
    *margin = bestM;
}

int main() {
    struct MenuItem m[5] = {
        {"Chicken Biryani", 450, 180, 45},
        {"Beef Burger", 350, 120, 20},
        {"Pasta Alfredo", 400, 100, 30},
        {"Fish Tikka", 550, 250, 35},
        {"Veggie Pizza", 500, 150, 25}
    };

    char bestDish[30];
    float margin;

    best(m, 5, bestDish, &margin);

    printf("Best Item: %s (Margin = %.2f)\n", bestDish, margin);

    return 0;
}

