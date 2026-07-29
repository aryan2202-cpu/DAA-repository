#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear scan - O(n)
int findPartitionLinear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) return i; // first index where 1 appears
    }
    return n; // no 1s found, all zeros
}

// Binary search - O(log n), works because array is sorted: 0...0 1...1
int findPartitionBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    int result = n; // default if no 1 found

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == 1) {
            result = mid;
            high = mid - 1; // look for an earlier 1
        } else {
            low = mid + 1;
        }
    }
    return result;
}

void generateArray(int arr[], int n, int transitionPoint) {
    for (int i = 0; i < n; i++) {
        arr[i] = (i < transitionPoint) ? 0 : 1;
    }
}

int main() {
    srand(time(NULL));

    int n = 20;
    int arr[20];
    int transitionPoint = 7; // where 1s start, e.g. arr[0..6]=0, arr[7..19]=1

    generateArray(arr, n, transitionPoint);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int linearResult = findPartitionLinear(arr, n);
    int binaryResult = findPartitionBinary(arr, n);

    printf("Linear scan found transition at index: %d\n", linearResult);
    printf("Binary search found transition at index: %d\n", binaryResult);

    return 0;
}