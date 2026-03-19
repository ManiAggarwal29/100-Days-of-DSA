/*
Problem: Height of Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>
// structure of node
struct node {
    int data;
    struct node *left, *right;
};
// create new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// function to find height
int height(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
int main() {
    // manually creating a sample tree
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Height of tree = %d", height(root));
    return 0;
}
