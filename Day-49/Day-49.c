/*
Problem: BST Insert
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int value) {
    
    // If tree is empty, create new node
    if (root == NULL) {
        return createNode(value);
    }

    // If value is smaller, go to left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If value is greater, go to right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (to display BST)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int n, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insert elements into BST
    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Display BST
    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
