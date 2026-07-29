#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long countComparisonsOptimized(int arr[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = arr[i];

    long comparisons = 0;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break; // already sorted, stop early
    }
    return comparisons;
}

long countComparisonsAlways(int arr[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = arr[i];

    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {100, 500, 1000, 2000, 5000, 8000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n,optimized_comparisons,always_comparisons\n");

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int *arr = malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        long optComp = countComparisonsOptimized(arr, n);
        long alwComp = countComparisonsAlways(arr, n);

        printf("%d,%ld,%ld\n", n, optComp, alwComp);

        free(arr);
    }

    return 0;
}