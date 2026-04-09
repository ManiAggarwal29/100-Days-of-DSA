/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->rear < q->front;
}

// Enqueue element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow!\n");
        exit(1);
    }
    q->items[++q->rear] = value;
}

// Dequeue element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    return q->items[q->front++];
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0}; // Adjacency matrix
    int inDegree[MAX] = {0}; // In-degree array
    Queue q;
    initQueue(&q);

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2 || u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge input.\n");
            return 1;
        }
        if (!adj[u][v]) { // Avoid duplicate edges
            adj[u][v] = 1;
            inDegree[v]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    printf("Topological Order: ");
    int count = 0;
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        count++;

        // Reduce in-degree of neighbors
        for (int v = 0; v < V; v++) {
            if (adj[node][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    // If count != V, graph has a cycle
    if (count != V) {
        printf("\nGraph contains a cycle. Topological sort not possible.\n");
    } else {
        printf("\n");
    }

    return 0;
}
