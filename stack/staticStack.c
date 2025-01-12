#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct staticStack
{
    int top;
    unsigned capacity;
    int* array;
}staticStack;

staticStack* create(unsigned capacity){
    staticStack* stack = (staticStack*)malloc(sizeof(staticStack));
    stack->capacity = capacity;
    stack->top = 1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(staticStack* stack){ //stack'in top'i capasity'nin -1'ine esitse true
    return (stack->top == stack->capacity -1);
}

int isEmpty(staticStack* stack){ //stack'in top'i -1'e esitse true
    return (stack->top == -1);
}

void push(staticStack* stack, int item){
    if (isFull(stack)){//overflow
        //if the stack is full instead of throwing an exception, we can replace the array with a larger one
        int *array2 = (int*)malloc(sizeof(int)*stack->capacity*2);
        for (int i = 0; i < stack->capacity; i++){
            array2[i] = stack->array[i];
        }
        free(stack->array);
        stack->array = array2;
        stack->capacity *=2;
    }
    stack->array[++stack->top] = item; //once top'i bir arttirt sonra indexe itemi isaretle
    printf("%d pushed to stack\n", item);
}

int pop(staticStack* stack){
    if (isEmpty(stack)){//isemptyden true gelirse yani capacitiy -1se yani stack bos pop kullanilamaz

        return INT_MIN;//C dilinde INT_MIN, limits.h başlık dosyasında tanımlı olan bir makrodur 
                       //ve bir int değişkeninin alabileceği minimum (en küçük) değerini ifade eder.
    }
    return(stack->array[stack->top--]);//once stackin topunu dondur sonra top i bir azalt
}

int peek(staticStack* stack){
    if (isEmpty(stack)){//underflow
        return INT_MIN;
    }
    return(stack->array[stack->top]);
}

void decreaseSize(staticStack* stack){
    //if the stack becomes less by popping some elements we need to decrease the size of array
    if (stack->top <= stack->capacity/4)
    {
        int *array2 = (int*)malloc(sizeof(int)*stack->capacity/2);
        for (int i = 0; i < stack->top; i++){
            array2[i] = stack->array[i];
        }
        free(stack->array);
        stack->array = array2;
        stack->capacity /=2;
    }
    
}

int main(){
    staticStack* stack = create(100);
    push(stack,10);
    push(stack,20);
    push(stack,30);

    printf("%d popped from stack\n", pop(stack));

    return 0;
}
    


