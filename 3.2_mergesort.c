//pra3.2 mergesort

#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right, int *iterations) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        (*iterations)++; // Increment the iteration count
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        (*iterations)++; // Increment the iteration count
    }

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort and count iterations
void mergeSort(int arr[], int left, int right, int *iterations) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, iterations);
        mergeSort(arr, mid + 1, right, iterations);

        // Merge the sorted halves
        merge(arr, left, mid, right, iterations);
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

    // Call the Merge Sort function and count iterations
    mergeSort(arr, 0, size - 1, &iterations);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Iterations executed during Merge Sort: %d\n", iterations);

    return 0;
}
