#include <stdlib.h>//malloclar icin falan
#include <stdio.h>//printf scanf icin falan
#include <limits.h>//Cdeki tanimli sabitler ve makrolar icin INT_MIN falan
#include <stdbool.h>//bu olmadan bool calismiyo


typedef struct StackNode{
    int top;
    int* array;
    unsigned capacity;
}stackNode;


void push(stackNode* stack, int item){
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));
    if (isFull(stack))
    {
        int* array2 = (int*)malloc(sizeof(stack->capacity*2));
        for (int i = 0; i < stack->capacity; i++)
        {
            array2[i] = stack->array[i];
        }
        free(stack->array);
        stack -> array = array2;
        stack -> capacity *= 2;
    }
    stack->array[++stack->top]= item;
}

int pop(stackNode* stack){
    if (isEmpyt(stack))
    {
        printf("stack underflow");
        return INT_MIN;
    }
    return stack->array[stack->top--];  
}

stackNode* createStack(int capacity){
    stackNode *stack = (stackNode*)malloc(sizeof(stackNode));
    stack->capacity = capacity;
    stack->top = 1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

//--------------------------------------------------------------
//reverse a word
void inverse(char text[]){
    int n = strlen(text);
    stackNode* stack = createStack(n);

    for (int i = 0; i < n; i++){
       push(stack,i);
    }

    for (int i = 0; i < n; i++){
        text[i] = pop(stack);
    }
}

//-----------------------------------------------------------------
//balancing symbols

bool isMatchingPair(char character1, char character2){
    if(character1 == '(' &&  character2 == ')'){
        return 1;
    }
    else if (character1 == '{' &&  character2 == '}'){
        return 1;
    }
    else if (character1 == '[' &&  character2 == ']'){
        return 1;
    }
    return 0;
}

bool areBacketsBalanced(char exp[]){
    int i = 0;
    stackNode* stack = NULL;

    while (exp[i]){
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            push(stack, exp[i]);
        }
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if (stack == NULL){
                return 0;
            }
            else if (!isMatchingPair(pop(stack),exp[i])){
                return 0;
            }
            i++;
        }
        
    }

    if (stack == NULL){
        return 1;
    }else{
        return 0;
    }
}

