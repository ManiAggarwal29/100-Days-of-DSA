/*
Problem: Perform DFS starting from a given source vertex using recursion.
*/
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;               // number of vertices

// DFS function using recursion
void DFS(int v) {
    visited[v] = 1;          // mark current node as visited
    printf("%d ", v);        // print the node

    for(int i = 0; i < n; i++) {
        // check if there is an edge and node is not visited
        if(adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);          // recursive call
        }
    }
}

int main() {
    int i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // initialize visited array
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("DFS Traversal: ");
    DFS(source);

    return 0;
}
