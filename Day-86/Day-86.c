/*
Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a
number is defined as the greatest integer whose square is less than or equal to the given number.
*/
#include <stdio.h>

int squareRoot(int x) {
    int low = 0, high = x;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == x) {
            return mid;
        }
        else if (mid * mid < x) {
            ans = mid;          // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x = 10;

    printf("Square root = %d", squareRoot(x));

    return 0;
}
