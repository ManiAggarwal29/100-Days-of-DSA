/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.
*/
#include <stdio.h>
#define V 5   // number of vertices

// Function to find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = 9999, min_index;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // store shortest distance
    int visited[V];   // track visited vertices

    // initialize
    for (int i = 0; i < V; i++) {
        dist[i] = 9999;   // infinity
        visited[i] = 0;
    }

    dist[src] = 0;

    // loop for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        // update distances
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// main function
int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0); // source = 0

    return 0;
}
