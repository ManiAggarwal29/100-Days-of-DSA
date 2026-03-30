/*
Construct a binary tree from given preorder and inorder traversal arrays.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Function to build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int preIndex = 0;

    if (start > end)
        return NULL;

    // Pick current node from preorder
    struct Node* root = newNode(preorder[preIndex++]);

    // If only one element
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, end);

    return root;
}

// Inorder print (to verify)
void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main
int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[]  = {4, 2, 5, 1, 3};
    int n = 5;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}
