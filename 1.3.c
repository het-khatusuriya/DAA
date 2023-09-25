//pra1.3 Linear and binary search 
#include <stdio.h>

// Function to perform a linear search on an array
int linearSearch(int arr[], int size, int target, int *iterations) {
    for (int i = 0; i < size; i++) {
        (*iterations)++; // Increment the iteration count
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Target not found
}

// Function to perform a binary search on a sorted array
int binarySearch(int arr[], int size, int target, int *iterations) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        (*iterations)++; // Increment the iteration count
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index if the target is found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int size;
    printf("Enter the length of the list: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d values for the list:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    int linearIterations = 0;
    int linearResult = linearSearch(arr, size, target, &linearIterations);
    if (linearResult != -1) {
        printf("Linear Search: Element found at index %d\n", linearResult);
    } else {
        printf("Linear Search: Element not found\n");
    }
    printf("Iterations executed in Linear Search: %d\n", linearIterations);

    int binaryIterations = 0;
    int binaryResult = binarySearch(arr, size, target, &binaryIterations);
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d\n", binaryResult);
    } else {
        printf("Binary Search: Element not found\n");
    }
    printf("Iterations executed in Binary Search: %d\n", binaryIterations);

    return 0;
}
