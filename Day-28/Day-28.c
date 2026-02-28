/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node *next;
};

// Function to create circular linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp, *newnode;
    int i;

    for(i = 1; i <= n; i++) {
        // Allocate memory
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Function to traverse circular linked list
void traverse(struct node *head) {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

// Main function
int main() {
    struct node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    traverse(head);

    return 0;
}
