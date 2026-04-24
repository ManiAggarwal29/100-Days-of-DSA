/*
Problem: Implement Selection Sort - Implement the algorithm.
*/
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;  // assume current index is minimum

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;  // update minimum index
            }
        }

        // swap elements
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    selectionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
