/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
*/
#include <stdio.h>
#define INF 1000000

struct Edge {
    int u, v, w;
};

int main() {
    int V = 5;  // vertices
    int E = 8;  // edges

    struct Edge edges[] = {
        {0,1,-1}, {0,2,4}, {1,2,3}, {1,3,2},
        {1,4,2}, {3,2,5}, {3,1,1}, {4,3,-3}
    };

    int dist[V];

    // Step 1: Initialize
    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[0] = 0; // source vertex

    // Step 2: Relax edges V-1 times
    for(int i = 1; i <= V-1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check negative cycle
    for(int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }

    // Print result
    printf("Shortest distances from source:\n");
    for(int i = 0; i < V; i++) {
        printf("Vertex %d -> %d\n", i, dist[i]);
    }

    return 0;
}
