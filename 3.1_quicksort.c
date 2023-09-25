//pra3.1 Quicksort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to perform Quick Sort and count iterations
int partition(int arr[], int low, int high, int *iterations) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*iterations)++; // Increment the iteration count
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *iterations) {
    if (low < high) {
        int pi = partition(arr, low, high, iterations);

        quickSort(arr, low, pi - 1, iterations);
        quickSort(arr, pi + 1, high, iterations);
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

    // Call the Quick Sort function and count iterations
    quickSort(arr, 0, size - 1, &iterations);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Iterations executed during Quick Sort: %d\n", iterations);

    return 0;
}
