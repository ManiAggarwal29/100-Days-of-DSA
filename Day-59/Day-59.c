/*
Construct a binary tree from given inorder and postorder traversal arrays.
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

// Search in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    static int postIndex = 4; // last index (n-1)

    if (start > end)
        return NULL;

    // Take current root
    struct Node* root = newNode(postorder[postIndex--]);

    // If single node
    if (start == end)
        return root;

    // Find index in inorder
    int inIndex = search(inorder, start, end, root->data);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, inIndex + 1, end);
    root->left  = buildTree(inorder, postorder, start, inIndex - 1);

    return root;
}

// Inorder print to verify
void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main
int main() {
    int inorder[]   = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}
