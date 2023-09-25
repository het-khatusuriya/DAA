//pra2.2 Selection Sort
#include <stdio.h>

// Function to perform Selection Sort and count iterations
void selectionSort(int arr[], int size, int *iterations) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            (*iterations)++; // Increment the iteration count
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int iterations = 0; // Initialize the iteration count

    // Call the Selection Sort function and count iterations
    selectionSort(arr, size, &iterations);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Iterations executed during Selection Sort: %d\n", iterations);

    return 0;
}
