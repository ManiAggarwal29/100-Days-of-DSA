/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue(){
    struct node *temp;
    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        free(temp);
        if(front == NULL)
            rear = NULL;
    }
}
void display(){
    struct node *temp = front;
    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue elements are:\n");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    int ch, x;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
