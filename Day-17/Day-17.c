/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.
*/
#include <stdio.h>

int main() {
    int arr[100], n, i;
    int max, min;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element as max and min
    max = arr[0];
    min = arr[0];

    // Find max and min
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Output result
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);

    return 0;
}
