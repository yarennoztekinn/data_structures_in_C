#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head;

int main(){
    return 0;
};

void insertAtBeginning(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;

    if (head == NULL){//LISTE BOS
        head = newNode;
        newNode->next = head; 

    }else{//liste dolu
        node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }//temp last node

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("\n insertion success");
}

void insertAtEnd(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;

    if (head == NULL){//LISTE BOS
        head = newNode;
        newNode->next = head; 

    }else{
        node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }//temp last node

        temp->next = newNode;
        newNode->next = head;
    }
    printf("\n insertion success");
}

void deleteBeginning(){
    if (head==NULL)
    {
        printf("\n list is empyt");
    }
    if (head->next == head)//one node
    {
        head = NULL;
        free(head);
    }else{
        node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }//temp last node

        temp->next = head->next;//headin point ettigi nodenin nextindeki adresi temp(last node)nin nextine veriliyo yani temp head nodeyi degil ondan sonrakine baglaniyo
        free(head);
        head = temp->next;
    }
}  

void deleteEnd(){
    if (head==NULL)
    {
        printf("\n list is empyt");
    }
    if (head->next == head)//one node
    {
        head = NULL;
        free(head);
    }else{
        node *temp = head;
        node *pretemp; 

        while (temp->next != head){
            temp = temp->next;
        }//temp last node

    }
}


