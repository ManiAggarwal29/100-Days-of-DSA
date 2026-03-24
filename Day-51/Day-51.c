/*
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of node
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

// Function to find LCA in BST
struct node* findLCA(struct node* root, int n1, int n2) {

    // Loop until we find LCA
    while (root != NULL) {

        // If both values are smaller → go left
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // If both values are greater → go right
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Otherwise, this is LCA
        else
            return root;
    }

    return NULL;
}
