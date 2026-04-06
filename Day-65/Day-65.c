/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix
bool visited[MAX];
int n; // number of vertices

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

bool hasCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    n = 4;

    // Example graph
    // 0-1, 1-2, 2-0 forms a cycle
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][0] = graph[0][2] = 1;

    if (hasCycle())
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}
