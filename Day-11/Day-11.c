/*
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
*/
#include <stdio.h>

int main() {
    int r, c;
    
    printf("Enter number of rows: ");
    scanf("%d", &r);
    
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int A[r][c], B[r][c], Sum[r][c];

    printf("\nEnter elements of first matrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Adding matrices
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nSum of the two matrices:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
