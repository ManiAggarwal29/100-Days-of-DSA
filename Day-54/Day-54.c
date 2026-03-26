/*
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// structure of tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// queue for level order traversal
struct node* queue[MAX];
int front = 0, rear = -1;

// enqueue function
void enqueue(struct node* temp)
{
    rear++;
    queue[rear] = temp;
}

// dequeue function
struct node* dequeue()
{
    return queue[front++];
}

// function to create new node
struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// zigzag traversal function
void zigzagTraversal(struct node* root)
{
    if (root == NULL)
        return;

    int leftToRight = 1;   // direction flag

    enqueue(root);

    while (front <= rear)
    {
        int size = rear - front + 1;   // nodes at current level
        int arr[MAX];   // temporary array to store level values

        // store nodes of current level
        for (int i = 0; i < size; i++)
        {
            struct node* temp = dequeue();
            arr[i] = temp->data;

            // insert left child
            if (temp->left != NULL)
                enqueue(temp->left);

            // insert right child
            if (temp->right != NULL)
                enqueue(temp->right);
        }

        // print according to direction
        if (leftToRight == 1)
        {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
        }
        else
        {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight;   // change direction
    }
}
// main function
int main(){
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);

    return 0;
}
