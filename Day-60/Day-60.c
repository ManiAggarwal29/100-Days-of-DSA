/*
Check whether a given binary tree satisfies the Min-Heap property.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Count total nodes
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is complete
int isComplete(struct node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
int isMinHeap(struct node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    // Both children exist
    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

// Main function to check heap
int checkHeap(struct node* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        return 1;
    else
        return 0;
}

int main() {
    // Example tree
    struct node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    if (checkHeap(root))
        printf("It is a Min-Heap\n");
    else
        printf("Not a Min-Heap\n");

    return 0;
}
