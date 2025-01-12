#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}stackNode;

stackNode* newNode(int data){
    stackNode* newNode =(stackNode*)malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(stackNode* head){
    return !head;
}

void push(stackNode** head,int data){
    stackNode* node = newNode(data);
    node->next = *head;
    *head = node;
    printf("%d pushed to the satck", data);
}

int pop(stackNode** head){
    if (isEmpty(*head)){
       return INT_MIN;
    }
    stackNode* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(stackNode* head){
    if (isEmpty(head)){
        return INT_MIN;
    }
    return head->data;
}

int main(){
    stackNode* head = NULL;

    push(&head,10);
    push(&head,20);
    push(&head,30);

    printf("%d popped from stack\n", pop(&head));

    printf("Top element is %d\n", peek(head));

    return 0;
}

