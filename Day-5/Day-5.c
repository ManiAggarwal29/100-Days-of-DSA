/*
A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
Input: - First line: integer p (number of entries in server log 1) 
Second line: p sorted integers representing arrival times from server 1  
Third line: integer q (number of entries in server log 2) 
Fourth line: q sorted integers representing arrival times from server 2)
*/
#include <stdio.h>
int main() {
    int p, q;
    // Input size of first log
    scanf("%d", &p);
    int A[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }
    // Input size of second log
    scanf("%d", &q);
    int B[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }
    int C[p + q];
    int i = 0, j = 0, k = 0;
    // Merge both arrays
    while(i < p && j < q) {
        if(A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of A
    while(i < p) {
        C[k] = A[i];
        i++;
        k++;
    }
    // Copy remaining elements of B
    while(j < q) {
        C[k] = B[j];
        j++;
        k++;
    }
    // Print merged array
    for(int i = 0; i < p + q; i++) {
        printf("%d ", C[i]);
    }
    return 0;
}
