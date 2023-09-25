#include <stdio.h>

// Global variable to count iterations
unsigned long long iterationCount = 0;

// Function to calculate Fibonacci series iteratively
void fibonacciIterative(int n) {
    int prev = 0, current = 1, next;

    printf("Fibonacci Series (Iterative) up to %d terms: ", n);

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = prev + current;
            prev = current;
            current = next;
        }

        printf("%d ", next);
        iterationCount++; // Increment the iteration count
    }

    printf("\n");
    printf("Iterations executed in iterative Fibonacci: %llu\n", iterationCount);
}

// Function to calculate Fibonacci series recursively
int fibonacciRecursive(int n) {
    iterationCount++; // Count the recursive function call
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of terms should be a positive integer.\n");
    } else {
        // Reset the iteration count
        iterationCount = 0;

        // Calculate and print the iterative Fibonacci series
        fibonacciIterative(n);

        // Reset the iteration count
        iterationCount = 0;

        // Calculate and print the recursive Fibonacci series
        printf("Fibonacci Series (Recursive) up to %d terms: ", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacciRecursive(i));
        }
        printf("\n");
        printf("Iterations executed in recursive Fibonacci: %llu\n", iterationCount);
    }

    return 0;
}
