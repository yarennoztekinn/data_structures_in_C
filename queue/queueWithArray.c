#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Queue{
    int front,rear;
    unsigned capacity;
    int*array;
}queue;

struct Queue* create(unsigned capacity){
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->array = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(queue *q){
    return(q->rear== q->capacity -1);
}

int isEmpty(queue *q){
    return(q->front == -1 || q->rear == -1);
}

void enqueue(queue *q, int item){
    if (isFull(q)){
        return;
    }
    if (q->front ==-1){//bos
       q->front ++;
    }

    q->array[++q->rear] = item;
}  

int dequeue(queue *q){
    if (isEmpty(q)){
        return;
    }
    if (q->front == q->capacity-1){//son eleman siliniyor
        q->front = -1;
        q->rear = -1;
        int item = q->array[q->front];
        return item;
    }
    int item = q->array[q->front++];
    return item;
}

    
