//pra2.3 insertionsort
#include <stdio.h>

// Function to perform Insertion Sort and count iterations
void insertionSort(int arr[], int size, int *iterations) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        (*iterations)++; // Increment the iteration count
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*iterations)++; // Increment the iteration count
        }
        arr[j + 1] = key;
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

    // Call the Insertion Sort function and count iterations
    insertionSort(arr, size, &iterations);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Iterations executed during Insertion Sort: %d\n", iterations);

    return 0;
}
