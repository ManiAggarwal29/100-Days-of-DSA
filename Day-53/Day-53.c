/*
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed
together from top to bottom and from left to right.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of tree node
struct node {
    int data;
    struct node *left, *right;
};

// Queue structure (to store node + hd)
struct qnode {
    struct node* tnode;
    int hd;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Simple queue using array
struct qnode queue[100];
int front = 0, rear = -1;

// Enqueue
void enqueue(struct node* root, int hd) {
    rear++;
    queue[rear].tnode = root;
    queue[rear].hd = hd;
}

// Dequeue
struct qnode dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// Vertical Order Traversal
void verticalOrder(struct node* root) {

    if (root == NULL) return;

    // Map using array (hd range assumed small)
    int map[200][100];   // storing nodes
    int count[200] = {0};

    int offset = 100; // to handle negative hd

    enqueue(root, 0);

    while (!isEmpty()) {
        struct qnode temp = dequeue();
        struct node* curr = temp.tnode;
        int hd = temp.hd;

        // Store node
        map[hd + offset][count[hd + offset]++] = curr->data;

        // Left child
        if (curr->left != NULL)
            enqueue(curr->left, hd - 1);

        // Right child
        if (curr->right != NULL)
            enqueue(curr->right, hd + 1);
    }

    // Print vertical order
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}
