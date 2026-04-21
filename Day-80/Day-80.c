/*
Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest
distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does 
not contain any negative weight cycles.
*/
#include <stdio.h>

#define INF 99999

int main() {
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    printf("\nShortest distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
