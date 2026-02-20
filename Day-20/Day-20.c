/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    // simple array used as hashmap (range assumed)
    int freq[20001] = {0};  // handle negative using shift
    int offset = 10000;

    freq[offset] = 1; // sum = 0 already seen once

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0) {
            count += freq[sum + offset];
        }

        freq[sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
