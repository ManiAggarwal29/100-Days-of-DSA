/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.
*/
#include <stdio.h>

int main() {
    int n, m, i, j, u, v, type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed graph, 0 for Undirected: ");
    scanf("%d", &type);

    // Input edges
    for(i = 0; i < m; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // If undirected, add reverse edge
        if(type == 0) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
