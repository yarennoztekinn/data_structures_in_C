#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;

}n;

n* newNode(int data){
    n* node = (n*)malloc(sizeof(n));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


n* insertLeft(n* root, int value){
    root->left= newNode(value);
    return root->left;
}

n* insertRight (n* root, int value){
    root->right= newNode(value);
    return root->right;
}

void inOrderTraversal(n* root){
    if (root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf("%d -> ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(n* root){
    if (root == NULL){
        return;
    }
    printf("%d -> ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(n* root){
    if (root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d -> ", root->data);
}



int main(){
    n* root = newNode(1);
    //root->left = newNode(2);
    //root->right = newNode(3);
    //root->left->left = newNode(4);
    

    insertLeft(root,12);
    insertRight(root,9);

    insertLeft(root->left,5);
    insertRight(root->left,6);

    printf("inorder traversal \n");
    inOrderTraversal(root);

    printf("\npreorder traversal \n");
    preOrderTraversal(root);

    printf("\npostorder traversal \n");
    postOrderTraversal(root);
   
}