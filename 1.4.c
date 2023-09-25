/* pra1.4 You are given two machine with capability to solve given problems
(10^(-4)*(2^n) Seconds and (10^(-6)*(2^n) Seconds respectively.
Implement a program that proves which algorithm is better for input
instance size n=10, 15, 20, 30 and 45. Also print time taken by each
machine for different values on n. Instead of machine A if we choose
to use machine C with capability (10^(-2)*(n^3), what kind of
significant improvement we may get. Show the detail analysis of it
using appropriate tool. */

#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to calculate the execution time for machine A
double machineA(int n) {
    return pow(2, n) * 1e-4;
}

// Function to calculate the execution time for machine B
double machineB(int n) {
    return pow(2, n) * 1e-6;
}

// Function to calculate the execution time for machine C
double machineC(int n) {
    return pow(n, 3) * 1e-2;
}

int main() {
    int inputSizes[] = {10, 15, 20, 30, 45};
    
    for (int i = 0; i < 5; i++) {
        int n = inputSizes[i];
        
        double timeA = machineA(n);
        double timeB = machineB(n);
        double timeC = machineC(n);
        
        printf("For n = %d:\n", n);
        printf("Machine A time: %.2e seconds\n", timeA);
        printf("Machine B time: %.2e seconds\n", timeB);
        printf("Machine C time: %.2e seconds\n", timeC);
        
        if (timeA < timeB)
            printf("Machine A is faster for n = %d\n", n);
        else
            printf("Machine B is faster for n = %d\n", n);
        
        if (timeC < timeA && timeC < timeB)
            printf("Machine C is significantly faster for n = %d\n", n);
        printf("\n");
    }
    
    return 0;
}
