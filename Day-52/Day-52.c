/*
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of tree node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find LCA
struct node* findLCA(struct node* root, int n1, int n2) {

    // Base case
    if (root == NULL)
        return NULL;

    // If any one node matches root
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right subtree
    struct node* left = findLCA(root->left, n1, n2);
    struct node* right = findLCA(root->right, n1, n2);

    // If both sides return non-NULL
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL value
    if (left != NULL)
        return left;
    else
        return right;
}
