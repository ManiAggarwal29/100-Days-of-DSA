/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.
*/
#include <stdio.h>
#include <stdlib.h>   // for abs()
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min_sum = 1000000;   // large value
    int x, y;
    // check all pairs
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }
    // output result
    printf("%d %d", x, y);
    return 0;
}
