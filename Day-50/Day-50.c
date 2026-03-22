/*
Problem: BST Search
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert function (to build BST)
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Search function
int search(struct node* root, int key) {
    
    // If tree is empty
    if (root == NULL) {
        return 0;  // Not found
    }

    // If key is found
    if (root->data == key) {
        return 1;
    }

    // Search in left subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // Search in right subtree
    return search(root->right, key);
}

// Main function
int main() {
    struct node* root = NULL;
    int n, value, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insert elements
    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Search key
    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }

    return 0;
}
