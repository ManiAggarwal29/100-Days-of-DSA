/*
Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
*/
#include <stdio.h>
int linearSearch(int arr[], int n, int k, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;          // count comparison
        if (arr[i] == k) {
            return i;              // key found
        }
    }
    return -1;                     // key not found
}
int main() {
    int n, k, index;
    int comparisons = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &k);
    index = linearSearch(arr, n, k, &comparisons);
    if (index != -1)
        printf("Key found at index %d\n", index);
    else
        printf("Key not found\n");
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}
