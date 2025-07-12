#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
   
}node;
struct node* head=NULL;
struct node* tail=NULL;
node *creatnode(int val){
    node* new =(node*)malloc(sizeof(node));
    new->data=val;
    new->next=NULL;
   
    return new;
}
void add_first(int val){
    node* new=creatnode(val);
    if(head==NULL){
        head=tail=new;
        tail->next=head;
    }else{
        new->next=head;
       head=new;
       tail->next=head;
    }
}
//add at last
void add_last(int val){
    node* new=creatnode(val);
    if(tail==NULL){
        head=tail=new;
        tail->next=head;
    }else{
      
        tail->next=new;
        tail=new;
        tail->next=head;
        
    }
}
// Display list forward
void display() {
    node *temp = head;
    printf("Linked list (forward):\n");
    while (temp->next !=head) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    add_first(50);
    add_first(40);
    add_first(30);
    add_first(20);
    add_first(10);
    add_first(00);
    display();
 
return 0;
} 