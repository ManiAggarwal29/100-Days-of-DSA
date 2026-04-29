/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the 
minimum distance between any two cows is maximized.
*/
#include <stdio.h>
#include <stdlib.h>

int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // first cow placed
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if(count == k)
            return 1; // possible
    }
    return 0; // not possible
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 5, k = 3;
    int stalls[] = {1, 2, 8, 4, 9};

    // sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 0;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1; // try bigger distance
        } else {
            high = mid - 1; // reduce distance
        }
    }

    printf("Maximum minimum distance = %d\n", ans);
    return 0;
}
