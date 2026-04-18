/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
bool visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int startNode, int n) {
    enqueue(startNode);
    visited[startNode] = true;

    while (front <= rear && front != -1) {
        int current = dequeue();
        for (int i = 0; i < n; i++) {
            // If there's an edge and the neighbor hasn't been visited
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n = 4; // Total number of vertices
    
    // Example: Initialize a simple connected graph
    // Edges: (0-1), (1-2), (2-3)
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;

    // Start BFS from node 0
    bfs(0, n);

    // Check if all nodes were visited
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
