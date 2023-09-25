#include <stdio.h>
#define N 3 
int findMin(int arr[N]) {
    int min = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
void greedyJobAssignment(int costMatrix[N][N]) {
    int workerAssignment[N];
    int jobAssigned[N] = {0};
    for (int i = 0; i < N; i++) {
        workerAssignment[i] = -1; // Initialize worker assignments to -1 (unassigned)
    }
    for (int i = 0; i < N; i++) {
        int minTime = findMin(costMatrix[i]);
        for (int j = 0; j < N; j++) {
            if (costMatrix[i][j] == minTime && jobAssigned[j] == 0) {
                workerAssignment[i] = j;
                jobAssigned[j] = 1;
                break;
            }
        }
    }
    printf("Optimal Job Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d assigned to Job %d\n", i + 1, workerAssignment[i] + 1);
    }
}
int main() {
    int costMatrix[N][N] = {
        {2, 6, 7},
        {4, 8, 3},
        {9, 5, 1}
    };
    greedyJobAssignment(costMatrix);
    return 0;
}
