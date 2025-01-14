#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}node;

node* newNode(int item){
    node * n= (node*)malloc(sizeof(node));
    n->data = item;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert(node * node, int item){
    if(node == NULL){//tree is empty 
        return newNode(item);
    }
    if(item < node->data){
        node-> left = insert(node->left,item);
    }
    else if(item > node->data){
        node->right = insert(node->right,item);
    }
    return node;// rootla esit item gelirse sadece mevcut nodeu dondurur
}



node* findMin(node* root){
    if (root != NULL){
        while (root->left != NULL){
            root= root->left;
        }
    }
    return root;
}

node* findMax(node* root){
    if (root == NULL){
        return NULL;
    }
    else if (root->right == NULL){
        return root;
    }
    else{
        return findMax(root->right);
    }
}

node* minValue(node* n){
    node * current = n;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;    
}

node* deletion(node* root, int item){
    if (root == NULL){
        return root;
    }
    if(item < root->data){//itemi bulmak icin
        root->left = deletion(root->left, item);
    }
    else if (item > root->data){
        root->right = deletion(root->right,item);
    }
    else{//son recursive cagrida itemi buldu -> root item
        if (root->left == NULL){ //root leaf ya da tek cocugu var 
            node * temp = root->right;//rootun sagi temp ile tutuldu. son recursive cagri nereden cagirildiysa (onceki if ya da else if) oraye return etti 
                                       //root->left ya da right i ile tutuldu
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            node * temp = root->left;
            free(root);
            return temp;
        }
        //rootun iki cocugu var 
        node* temp= minValue(root->right);//inordersuccessor -> smallest in the right sub tree

        root->data = temp->data; //change the data with the succesor's data

        root->right = deletion(root->right, temp->data) ; //root un rigt i yazdik cunku subtreedeki succesorun yerinde artik silinmek istenen sayi var 
                                                          //ve bu subtreenin kokunu yani root->rightini deletion fonskiyonuna verdik
    }
    return root;
}

node* search(node* root, int data) {
    node* current = root;

    while (current != NULL) {
        if (current->data == data) { // Aranan eleman bulundu
            return current;
        }

        if (data < current->data) {  // Sol alt ağaca git
            current = current->left;
        } else {                     // Sağ alt ağaca git
            current = current->right;
        }
    }
    return NULL; // Eleman bulunamadı
}



int main(){
    node* root = NULL;
    root = insert(root,50);// 50 ile new node olusturur bunu rote a point ettirir

    insert(root,30);// since 30<50 -> node->left= (node->left,30), since node->left=NULL -> newNode(30) return eder ve node->left'e point ettirilir
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    printf("\n max: %d",findMax(root)->data);
    printf("\n min: %d",findMin(root)->data);

    return 0;
}    