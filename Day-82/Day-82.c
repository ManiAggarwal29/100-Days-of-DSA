/*
Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound 
operations using Binary Search.
Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.
*/
#include <stdio.h>

// Lower Bound function
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;        // possible answer
            high = mid - 1;   // move left
        } else {
            low = mid + 1;    // move right
        }
    }
    return ans;
}

// Upper Bound function
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;        // possible answer
            high = mid - 1;   // move left
        } else {
            low = mid + 1;    // move right
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 4, 4, 5, 7};
    int n = 6;
    int x = 4;

    printf("Lower Bound index = %d\n", lowerBound(arr, n, x));
    printf("Upper Bound index = %d\n", upperBound(arr, n, x));

    return 0;
}
