//pra2.1 Bubble sort
#include <stdio.h>

// Function to perform Bubble Sort and count iterations
void bubbleSort(int arr[], int size, int *iterations) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            (*iterations)++; // Increment the iteration count
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Call the Bubble Sort function and count iterations
    bubbleSort(arr, size, &iterations);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Iterations executed during Bubble Sort: %d\n", iterations);

    return 0;
}
