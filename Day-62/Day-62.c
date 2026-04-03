/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjLists; // Array of pointers
};

// Create node and graph, and add undirected edges
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    // For directed, remove the following 3 lines
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
