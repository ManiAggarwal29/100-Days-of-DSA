/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }

    // push into stack
    stack[++top] = v;
}

// Topological Sort function
void topologicalSort() {
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }

    printf("Topological Order:\n");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // initialize visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    topologicalSort();

    return 0;
}
