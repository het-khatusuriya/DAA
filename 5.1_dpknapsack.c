/* pra5.1  knapsack problem using dynamic programming

AIM: Let S be a collection of objects with profit-weight values. Implement the 0-1 knapsack problem for S assuming we have a sack that can hold objects with total weight W.
 */
#include <stdio.h>
struct Object {
    int profit; // Profit of the object
    int weight; // Weight of the object
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(struct Object objects[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (objects[i - 1].weight <= w) {
                dp[i][w] = max(objects[i - 1].profit + dp[i - 1][w - objects[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main() {
    int n;
    int capacity;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    struct Object objects[n];
    printf("Enter the profit and weight of each object:\n");
    for (int i = 0; i < n; i++) {
        printf("Object %d (profit weight): ", i + 1);
        scanf("%d %d", &objects[i].profit, &objects[i].weight);
    }
    printf("Enter the maximum weight capacity of the knapsack: ");
     scanf("%d", &capacity);
    int max_profit = knapsack(objects, n, capacity);
    printf("The maximum profit that can be obtained is: %d\n", max_profit);
    return 0;
}

