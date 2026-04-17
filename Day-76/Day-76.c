/*
Problem Statement
Using DFS or BFS, count number of connected components.
*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;   // mark node as visited
    
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);   // visit neighbor
        }
    }
}

int main() {
    int edges, u, v;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize matrix to 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // input edges
    for(int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // count connected components
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i);
            count++;
        }
    }

    printf("Number of connected components = %d\n", count);

    return 0;
}
