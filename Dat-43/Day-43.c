/*
Construct a Binary Tree from the given level-order traversal.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct node* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for (int i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n)
            nodes[i]->left = nodes[left];

        if (right < n)
            nodes[i]->right = nodes[right];
    }

    return nodes[0]; 
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    printf("Preorder Traversal of constructed tree: ");
    preorder(root);

    return 0;
}
