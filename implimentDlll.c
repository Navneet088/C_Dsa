#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
struct node* head=NULL;
struct node* tail=NULL;
node *creatnode(int val){
    node* new =(node*)malloc(sizeof(node));
    new->data=val;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
//add at first 
void add_first(int val){
    node* new=creatnode(val);
    if(head==NULL){
        head=tail=new;
    }else{
        new->next=head;
        head->prev = new;
        head=new;
    }
}
//add at last
void add_last(int val){
    node* new=creatnode(val);
    if(tail==NULL){
        head=tail=new;
    }else{
        new->prev = tail;
        tail->next=new;
        tail=new;
        
    }
}
void add_at_specific(int val, int pos){
    node* new=creatnode(val);
    if(head==NULL){
        head=tail=new;
        return;
    }
    if(pos==1){
        add_first(val);
        return;
    }
    node *temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;

    }
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
}

// Display list forward
void display() {
    node *temp = head;
    printf("Linked list (forward):\n");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//delete from first 
void delet_first(){
    if(head==NULL){
        printf("list is empty");  
    }
    else{
        node*temp=head;
        printf("deleted element: %d\n",temp->data);
        head=head->next;
        if (head != NULL)
        head->prev = NULL;
        free(temp);
    }
}
//delete from last
void delet_last(){
    if(tail==NULL){
        printf("list is empty");  
        return;
    }
        node*temp=tail;
        printf("deleted element: %d\n",temp->data);
        tail=tail->prev;
        if (tail != NULL)
         tail->next = NULL;
       
        free(temp);
  
}
void delet_from_spacificpos(int pos){
    if(head==NULL){
        printf("list is empty"); 
         return;
    }
    if(pos==1){
        delet_first();
        return;
    }
    node* temp=head;
    for(int i=1; i<pos && temp!=NULL; i++){
        temp=temp->next;
    }
    printf("deleted element: %d\n",temp->data);
    temp->prev->next=temp->next;
    temp->next->prev = temp->prev;
    free(temp);

}
//display back ward
void displayback() {
    node *temp = tail;
    printf("Linked list (backward):\n");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->prev; 
}
printf("NULL\n");
}
int main(){

add_first(5);
add_first(10);
add_first(15);
add_first(20);
add_first(25);
add_last(12);
display();
delet_first();
delet_last();
display();
add_at_specific(12,2);
display();
delet_from_spacificpos(2);
display();
displayback();
    return 0;
}