/*
Problem: Level Order Traversal
Implement the solution for this problem.
Input:
- Input specifications
Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node {
    int data;
    struct node *left, *right;
};
// Create new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Queue for level order
struct node* queue[100];
int front = -1, rear = -1;
void enqueue(struct node* root) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = root;
}
struct node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}
// Level Order Traversal
void levelOrder(struct node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (front <= rear) {
        struct node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Level Order Traversal:\n");
    levelOrder(root);
    return 0;
}
