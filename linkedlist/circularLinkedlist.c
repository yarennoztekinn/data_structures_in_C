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

void deleteFromBeginning(){
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
        head = temp->next;//temoin nexti artik silinen nodeden sonraki yeni ilk head node olacagi icin head tekrardan listenin head pointerina point eder
    }
}  

void deleteFromEnd(){
    if (head==NULL)
    {
        printf("\n list is empyt");
    }

    if (head->next == head)//one node
    {
        head = NULL;
        free(head);
    }
    else{
        node *temp = head;
        node *pretemp = temp; 

        while (temp->next != head){
            pretemp = temp;
            temp = temp->next;
        }//temp last node ve pretemp ondan onceki node

        pretemp->next = temp->next;//pretemp'e, tempin nextindeki head nodenin adresini assign ediyoruz boylece last nodeden onceki node head nodeyi point etmeye basliyo
        free(temp);
    }
}

// -------------------------- circular doubly linked list----------------------

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;    
}node2; 

node2 *head2;

void insertBeginning(int data){
    node2 *ptr = (node*)malloc(sizeof(node2));
    ptr->data = data;

    if (head2 == NULL)//list is empty
    {
        ptr->next = head2;
        ptr->prev = head2;
    }
    else{//there ara more than one node
        node2 * temp = head2;

        while (temp -> next != head2)
        {
            temp = temp-> next;
        }//temp is last node

        temp -> next = ptr;
        ptr -> prev = temp;
        ptr -> next = head2;
        head2 -> prev = ptr;
        head2 = ptr;
    }
}

void insertEnd(int data){
    node2 *ptr = (node*)malloc(sizeof(node2));
    ptr->data = data;

    if (head2 == NULL)//list is empty
    {
        ptr->next = head2;
        ptr->prev = head2;
    }
    else{//there ara more than one node
        node2 * temp = head2;

        while (temp -> next != head2)
        {
            temp = temp-> next;
        }//temp is last node
        temp -> next = ptr;
        ptr -> prev = temp;
        ptr -> next = head2;
        head2 -> prev = ptr;
        }
}


void deleteBeginng(){
    if (head2 == NULL)
    {
        printf("\nlist is already empty\n");
        exit(1);
    }
    node2 * temp = head2;
    
    if (temp->next == head2){//tek node
        head2 == NULL;
        free(head);
    }
    else//cok node
    {
        while(temp->next != head2){
            temp = temp->next;
        }
        temp->next = head2->next;
        head2->next->prev= temp;
        free(head2);
        head2 = temp->next;
    }
}

void deleteEnd(){
    if (head2 == NULL)
    {
        printf("\nlist is already empty\n");
        exit(1);
    }
    node2 * temp = head2;
    
    if (temp->next == head2){//tek node
        head2 == NULL;
        free(head);
    }
    else//cok node
    {
        while(temp->next != head2){
            temp = temp->next;
        }
        temp->prev->next=head2;
        head2->prev = temp->prev;
        free(temp);
    }
}
