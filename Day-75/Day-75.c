/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous 
subarray whose sum is equal to zero.
*/
#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // simple array as hashmap (for small range)
    int map[1000];
    for(int i = 0; i < 1000; i++)
        map[i] = -2;   // -2 means not visited

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            max_length = i + 1;

        if(map[sum + 500] != -2) {
            int len = i - map[sum + 500];
            if(len > max_length)
                max_length = len;
        }
        else {
            map[sum + 500] = i;
        }
    }
    return max_length;
}

int main() {
    int arr[] = {1, -1, 3, 2, -2, -3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Length = %d", maxLen(arr, n));
    return 0;
}
