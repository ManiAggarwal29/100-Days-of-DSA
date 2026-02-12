/*
Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to 
be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position 
[i][j] is equal to element at position [j][i] for all valid i and j).
*/
#include <stdio.h>
int main() {
    int n, i, j;
    int matrix[100][100];
    int isSymmetric = 1;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    printf("Enter elements of matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Check symmetric condition
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }
    if(isSymmetric == 1)
        printf("Matrix is Symmetric\n");
    else
        printf("Matrix is Not Symmetric\n");
    return 0;
}
