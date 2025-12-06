#include <stdio.h>
// recursive function (using GIVEN parameters)
int calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets) {
    // BASE CASE 
    if (fuel <= 0) {
        printf("Fuel finished\n");
        return 0;
    }
    if (planet > totalPlanets) {
        printf("All planets visited\n");
        return 1;
    }
    // fuel consumption to reach on a planet
    fuel -= consumption;
    // gravitational recharge
    fuel += recharge;
    // solar recharge after every single 4th planet
    if (planet % 4 == 0) {
        fuel += solarBonus;
    }
    // fuel status for the current planet
    printf("Planet %d: \t||||| \tFuel Remaining = %d\n", planet, fuel);
    // recursive calling
    return calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}
// FUNCTION main
int main() {
    int fuel, consumption, recharge, solarBonus, totalPlanets;
    // input
    printf("Enter initial fuel: ");
    scanf("%d", &fuel);
    printf("Enter fuel consumption per planet: ");
    scanf("%d", &consumption);
    printf("Enter gravitational recharge: ");
    scanf("%d", &recharge);
    printf("Enter solar bonus (after every 4th planet): ");
    scanf("%d", &solarBonus);
    printf("Enter total number of planets: ");
    scanf("%d", &totalPlanets);
    printf("\n--- Spacecraft Fuel Simulation ---\n");
    calculateFuel(fuel, consumption, recharge, solarBonus, 1, totalPlanets);
    return 0;
}

