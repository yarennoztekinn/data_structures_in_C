#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head;//linkedlistteki bas nodenin adresini tutmak(ona point etmek) icin node pointeri olusturuldu

void main(){
    int choice, item, loc;
    do
    {
        printf("\nEnter the item which you want to insert\n");
        scanf("%d",&item);
        if(head == NULL)
        {
            beginsert(item);
        }
        else
        {
            randominsert(item);//sacma oldu ama olay mantik gfbdvhjfdg
        }
        printf("\nPress 0 to insert more\n");
        scanf("%d",&choice);
    }while(choice == 0);
}

void beginsert(int item){
    node *ptr =(node*)malloc(sizeof(node));//arguman olarak verilen int itemi linked liste eklemek icin olusturulacak nodenin memorydeki yeri malloc ile allocate edildi ve adres onu point etmek icin olusturulan ptr pointerine tutturuldu

    if(ptr==NULL) //eger ptr null ise yukaridaki islemde bos memory bulunamamis ve stack dolmustur
    {
        printf("\nOVERFLOW\n");
    }
    else //bos alan var
    {
        ptr->data = item;//olusturulan nodeye istenilen item yuklendi
        ptr->next = head;//headin tuttugu adresteki listtenin basi olan nodeye yeni olusturulan node baglandi
        head = ptr;//ptrdaki yeni olusturulan nodenin adresi heade assign edildi yani head ile listedeki eski bas node arasindaki bag koptu yeni bas node olacak olan yeni olusturulan node arsinda bag kuruldu 
        printf("\nNode inserted\n");
    }
}

void lastinsert(int item){
    node *ptr = (node*)malloc(sizeof(node));

    node *temp;// linkedlistin sonuna kadar gitmek icin gecici bir node pointeri olustur

    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr->data = item;

        if (head == NULL)// liste boşsa
        {
            ptr->next = NULL;//ptr nextini bos yap
            head = ptr; //head ile point et
            printf("\nNode inserted\n");
        }
        else//liste boş degilse
        {
            temp = head;// temp baslangic nodesinin adresi onu tutan head pointeri ile gecici nodeye assign edilmis yani gecici node pointeri baslangic nodesini point ederk basliyo
            while(temp -> next != NULL)//temp listenin sondan onceki nodunu point edene kadar  
            {
                temp = temp -> next;// temp i ilerlet
            }// temp sondan onceki nodu point ediyo
            temp -> next = ptr;// (temp->next)son nodeun adresini tutar ve ptrin tuttugu yeni nodeun adresi temp->nexte assign edilmis yani ptrin gosterdigi node son node
            ptr -> next = NULL;//ptrnin next i null yapilir
            printf("\nNode inserted\n");
        } 
    }
}

 void randominsert(int item){
    node *ptr = (node*)malloc(sizeof(node));

    node *temp;// yine gecici bir node pointeri olusturulmus istenilen konuma gelmek icin 

    int loc;

    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter the location you want to insert the item\n");
        scanf("%d",&loc);

        ptr->data = item;
        
        temp = head;// 
        for (int i = 0; i < loc; i++)
        {
            temp = temp -> next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }  
        }//temp istenilen konumdan onceki nodeyi point ediyo
        ptr -> next = temp -> next;//istenilen konumdan sonraki nodenin adresi ptrin nextine assign ediliyo yani sonraki node ile yeni node arasindaki bag kuruldu
        temp -> next = ptr;//istenilen konumdan onceki nodeyi point eden tempin point ettigi nodeun nextine ptrin point ettigi konumdaki nodenin adresi assign ediliyo yani onceki node ile yeni node arasindaki bag kuruldu
        printf("\nNode inserted\n");
    }
 }

 void begdelete(){
    node *ptr;
    if(head==NULL){//liste zaten bos
        printf("\n list is empty");
    }
    else{//listede en az 1 node var
        ptr = head;// headin tuttugu ilk nodenin adresi gecici olusturdugumuz node pointerina verilir ptr de ilk nodeyi gosteriyo
        head = ptr -> next; // heade ptrnin point ettigi nodenin nexti olan bastan ikinci nodenin adresi verilir head artik onu point ediyo
        free(ptr);//gecici ptr pointeri free fonksiyonuyla yok edilir. eski en bastaki silinmek istenen nodeyi gosteren tek pointer ptr oldugunda node de ptr ile silinmis olur
        printf("\n Node is deleted from the beginning.");
    }
 }

 void end_delete(){
    node *ptr,*ptr1;
    if(head==NULL){//liste zaten bos
        printf("\n list is empty");
    }
    else if(head->next == NULL){// listede tek node var
        head = NULL;//normalde head pointeri listedeki tek olan nodeyi point ediyo ama onu nulla assign ederek aralarindaki bagi kopartiyoruz boylelikle node silindi
        free(head);// null i gosteren bellekte bos yer kaplayan pointer de siliniyo
        printf("\n only node o flist deleted.");
    }
    else{
        ptr = head; //gecici olusturulan ptr pointerinina headin tuutugu head nodenin adresi veriliyo
        while (ptr -> next != NULL)//ptr son nodeyi gosterene dek 
        {
            ptr1 = ptr; // ptrin tuttugu adresi ptr1 e veriliyo ayni nodeyi gosteriyolar
            ptr = ptr -> next; //sonra ptrin nextinin adresi ptr a assign edilerek ptr bir bir ilerletiliyo ptr1 de onu 1 geriden takip etmis oluyo
        }//ptr son nodeyi point ettiginde ptr1 de sondan bir oncekini point ettiginde dongu sonlaniyo
        ptr1->next = NULL;//sondan bir oncekinode normalde son nodenin adresini nextinde tutarken onu null yaparak aralarindaki bagi kopariyoruz 
        free(ptr); //son nodeyi gosteren bode pointeri de silinine onun point ettigi (eski) son node de siliniyo cunku sondan bir onceki ile aralarindaki bagi da kopardik
        printf("\n Node is deleted from the last.");
    }
 }

 void delete_specified(){
    node *ptr, *ptr1;
    int loc;
    scanf("%d",&loc);
    ptr = head;
    for (int i = 0; i < loc; i++)//ptr silinmek istenen nodeyi point edene kadar
    {
        ptr1 = ptr; // ptr1 ptrin nopdesini point ettirilir
        ptr = ptr-> next;//ptr adim adim ilerletilir
        if (ptr == NULL)//eger i loca gelmeden ptr null olursa 
        {
            printf("\nThere are less than %d elements in the list.\n",loc);//liste istenilen loctan daha kisadir
            return;
        }    
    }//ptr silinmek istenen nodeyi ptr1 de ondan bir oncekini point ediyor
    ptr1 -> next =ptr -> next;//ptrin nextindeki adres(silinmek istenen nodeden sonraki nodenin adresi) ptr1in nextine assign edilir. ptr1 in nodesi ile ptrin nodesi arasindaki bag koptu ptr1 ile ptrdan sonraki node baglandi
    free(ptr);// silinmek istenen nodeyi point eden tek pointer olan ptr silinir dolayisiyla silinmek istenn node de silinmis olur.
    printf("\n Node is deleted from the location %d.\n",loc);
 }

void traverse(){
    node *ptr;
    ptr = head;
    if(head==NULL){//liste zaten bos
        printf("\n list is empty");
    }
    else{//liste dolu
        while(ptr != NULL){// ptr son nodeyi gosterene kadar
            printf("\n%d",ptr->data);// ptrin gosterdigi nodenin datasini yazdir 
            ptr = ptr -> next;//ptri bir sonraki nodeye point ettirt
        }
    }
}

void search(){
    node *ptr;
    int item,i = 0, flag;
    ptr = head;

    if(head==NULL){//liste zaten bos
        printf("\n list is empty");
    }
    else{//liste dolu
        printf("\n enter the item which you want to search\n");
        scanf("%d",&item);

        while (ptr != NULL)// ptr listedeki son nodeyi gostermedikce
        {
            if (ptr->data == item)//eslesme var
            {
                printf("\n item found at location %d",i +1);//item bulundu
                flag = 0;//flag 0 yapildi ki itemin bulundugu anlasilsin asagida if e girmesin
                break;//en icteki donguyu sonlandirdi yani while i 
            }
            else// eslesme yok
            {
            flag =1;//flag 1 yapildi hic if e girmezse while in disindaki if e grisin diye
            }
            i++;//location arttirdi 
            ptr = ptr->next; //ptr i bir bir kaydirdi
        }//ptr son nodeyi gosteriyor
        if (flag==1)//flag 1 ise if e hic girmemis demektir yani item listede bulunamamis
        {
            printf("\n item not found.\n");
        }
    }
}

int countnode(node *st){
    if(st == NULL){
        return 0;
    }else{
        return(1 + countnode(st->next));
    }
}



