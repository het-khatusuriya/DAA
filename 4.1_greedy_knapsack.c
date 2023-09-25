/* pra4.1 Franctional knapsack using greedy
AIM: A Burglar has just broken into the Fort! He sees himself in a room with n piles of gold dust. Because each pile has a different purity, each pile also has a different value (v[i]) and a different weight (w[i]). A Burglar has a bag that can only hold W kilograms. Calculate which piles Burglar should completely put into his bag and which he should put only fraction into his bag. Design and implement an algorithm to get maximum piles of gold using given bag with W capacity, Burglar is also allowed to take fractional of pile.
Software Required/Hardw
*/

#include <stdio.h>
#include <stdlib.h>
// Structure to represent a pile of gold dust
struct GoldPile {
    double value;
    double weight;
};
// Function to compare piles based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    double ratioA = ((struct GoldPile*)a)->value / ((struct GoldPile*)a)->weight;
    double ratioB = ((struct GoldPile*)b)->value / ((struct GoldPile*)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}
// Function to calculate the maximum value of gold dust that can be obtained
double fractionalKnapsack(struct GoldPile* piles, int n, double W) {
    // Sort the piles by value-to-weight ratio in descending order
    qsort(piles, n, sizeof(struct GoldPile), compare);
    double totalValue = 0.0;  // Total value of gold dust in the bag
    double currentWeight = 0.0;  // Current weight of gold dust in the bag
    // Iterate through the sorted piles and add them to the bag
    for (int i = 0; i < n; i++) {
        if (currentWeight + piles[i].weight <= W) {
            // If the entire pile can fit in the bag, add it
            totalValue += piles[i].value;
            currentWeight += piles[i].weight;
        } else {
            // Otherwise, add a fraction of the pile to fill the bag
            double remainingSpace = W - currentWeight;
            totalValue += (piles[i].value / piles[i].weight) * remainingSpace;
            break;  // Bag is full
        }
    }
    return totalValue;
}
int main() {
    int n;
    printf("Enter the number of gold piles: ");
    scanf("%d", &n);
    struct GoldPile* piles = (struct GoldPile*)malloc(n * sizeof(struct GoldPile));
    printf("Enter the values and weights of the gold piles:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &piles[i].value, &piles[i].weight);
    }
    double W;
    printf("Enter the capacity of the bag (in kilograms): ");
    scanf("%lf", &W);
    double maxValue = fractionalKnapsack(piles, n, W);
    printf("Maximum value of gold that the burglar can take = %.2lf\n", maxValue);
    free(piles);
    return 0;
}
