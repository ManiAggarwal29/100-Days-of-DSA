#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node* next;
};

// Front and Rear pointers
struct node* front = NULL;
struct node* rear = NULL;

// Enqueue operation (Insert at rear)
void enqueue(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }

    printf("Inserted: %d\n", value);
}

// Dequeue operation (Delete from front)
void dequeue() {
    // Check if queue is empty
    if (front == NULL) {
        printf("Queue is EMPTY\n");
        return;
    }

    struct node* temp = front;
    printf("Deleted: %d\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// Display queue
void display() {
    struct node* temp = front;

    if (temp == NULL) {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
