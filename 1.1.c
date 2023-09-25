//pra1.1 Factorial (Iterative and Recursive)
#include <stdio.h>

// Function to calculate factorial iteratively
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate factorial recursively
unsigned long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long iterResult = factorialIterative(n);
        unsigned long long recurResult = factorialRecursive(n);

        printf("Iterative Factorial of %d: %llu\n", n, iterResult);
        printf("Recursive Factorial of %d: %llu\n", n, recurResult);
    }

    return 0;
}
