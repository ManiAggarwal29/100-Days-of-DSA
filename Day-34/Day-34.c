/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop(){
    struct node *temp;
    int val;

    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int evaluate(char postfix[]){
    int i=0, a, b, result;

    while(postfix[i] != '\0'){
        
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');  
        }
        else{
            b = pop();
            a = pop();

            switch(postfix[i]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main(){
    char postfix[50];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int ans = evaluate(postfix);

    printf("Result = %d", ans);

    return 0;
}
