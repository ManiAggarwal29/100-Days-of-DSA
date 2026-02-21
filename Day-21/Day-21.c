/*
Problem: Create and Traverse Singly Linked List
*/
#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // creating linked list
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // traversing linked list
    printf("Linked List Elements: ");
    temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
