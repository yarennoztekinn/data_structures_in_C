#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}n;

n* newNode(int data){
    n* newNode = (n*)malloc(sizeof(n));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void NthInOrder(n* node, int n){
    static int count = 0;
    if (node == NULL){
       return;
    }
    if (count <= n){
        NthInOrder(node->left,n);
        count++;

        if (count == 0){
            printf("%d", node->data);
        }

        NthInOrder(node->right, n);
    }
}

int main(){
    n* root = newNode(0);
    root->left = newNode(20);
    root->left = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    int n = 4;

    NthInOrder(root,n);
    return 0;
}

int addBt(n* root){
    if (root==NULL){
        return 0;
    }
    return(root->data + addBt(root->left)+ addBt(root->right));
}