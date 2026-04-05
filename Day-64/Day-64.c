/*
Problem: Perform BFS from a given source using queue.
*/
#include <stdio.h>
#include <stdlib.h>

// Define tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node for BFS
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return; // queue full
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return node;
}

// BFS traversal (level order)
void BFS(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
}

// Helper to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("BFS (Level Order Traversal):\n");
    BFS(root);

    return 0;
}
