#include <stdio.h>
#include <limits.h>

// Function to find the optimal way to parenthesize matrices and calculate minimum scalar multiplications
void matrixChainMultiplication(int dimensions[], int n) {
    // Create a table to store the number of scalar multiplications
    int dp[n][n];

    // Initialize the table with 0
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int chainLength = 2; chainLength < n; chainLength++) {
        for (int i = 1; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", dp[1][n - 1]);
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1]; // Matrix dimensions, including the start and end dimensions
    printf("Enter the dimensions of matrices (e.g., for A1, A2, A3, enter dimensions as A0xA1, A1xA2, A2xA3, ...):\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dimensions[i]);
    }

    matrixChainMultiplication(dimensions, n + 1);

    return 0;
}
