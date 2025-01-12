#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct QueueNode{
    int item;
    struct QueueNode* next;
};

struct Queue{
    struct QueueNode *front, *rear;
};

struct QueueNode* createNode(int item){
    struct QueueNode* newNode =(struct QueueNode*)malloc(sizeof(struct QueueNode));

    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enQueue(struct Queue* queue, int item){
    struct QueueNode* newNode = createNode(item);
    if (queue->front == NULL){//bos
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

void deQueue(struct Queue* queue){
    if (queue->front == NULL){//bos
        return;
    }
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front==NULL){//if front becomes null change rear also null(-1)
        queue->rear = NULL;
    }
    free(temp);
}

int main(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    enQueue(q, 50); 
    enQueue(q, 60);   
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    deQueue(q);
    
    printf("Queue Front : %d\n", q->front->item);
    printf("Queue Rear : %d\n", q->rear->item);
    return 0;
}