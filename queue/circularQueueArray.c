#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Queue{
    int front,rear,size;
    unsigned capacity;
    int*array;
}queue;

struct Queue* create(unsigned capacity){
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity -1;//?
    q->array = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(queue *q){
    return (q->size == q->capacity);
}

int isEmpty(queue *q){
    return (q->size == 0);
}

void enqueue(queue *q, int item){
    if (isFull(q)){
        return;
    }
    q->rear = (q->rear + 1 ) % q->capacity; // 3+1%5 = 4  5+1%5= 1
    q->array[q->rear] = item;
    q->size = q->size +1; 
}

int dequeue(queue *q){
    if (isEmpty(q)){
        return INT_MIN;
   }        
   int item = q->array[q->front];
   q->front = (q->front + 1) % q->capacity;
   q->size = q->size + 1;
   return item;
}