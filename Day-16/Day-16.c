/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.
*/
#include <stdio.h>

int main() {
    int arr[100], n, i, j, count;
    int visited[100] = {0};   // to mark counted elements

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(i = 0; i < n; i++) {
        
        // Skip if already counted
        if(visited[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;   // mark as counted
            }
        }

        // Print result
        printf("%d occurs %d times\n", arr[i], count);
    }

    return 0;
}
