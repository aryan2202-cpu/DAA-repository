#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Naive method - O(n^2) - compare every pair
int hasDuplicatesNaive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return 1; // duplicate found
        }
    }
    return 0; // all unique
}

// Better method - O(n log n) - sort first, then check neighbors
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hasDuplicatesSorted(int arr[], int n) {
    int *copy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copy[i] = arr[i];

    qsort(copy, n, sizeof(int), cmp);

    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        if (copy[i] == copy[i + 1]) {
            found = 1;
            break;
        }
    }
    free(copy);
    return found;
}

void generateArray(int arr[], int n, int range) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
}

int main() {
    srand(time(NULL));

    int n = 20;
    int arr[20];

    // Small range forces likely duplicates; large range makes uniqueness likely
    generateArray(arr, n, 15); // range smaller than n -> duplicates guaranteed

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Naive method  -> duplicates found: %s\n", hasDuplicatesNaive(arr, n) ? "YES" : "NO");
    printf("Sorted method -> duplicates found: %s\n", hasDuplicatesSorted(arr, n) ? "YES" : "NO");

    return 0;
}