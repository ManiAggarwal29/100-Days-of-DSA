/*
Problem: Given an array of integers, rotate the array to the right by k positions.
*/
#include <stdio.h>
int main() {
    int n, k, i, j, temp;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    // Rotation
    for(i = 0; i < k; i++) {
        temp = arr[n-1];
        for(j = n-1; j > 0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

