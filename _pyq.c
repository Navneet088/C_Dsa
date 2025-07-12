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
void add_last(int val){
    node *new=creatnode(val);
    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        tail->next = new;
        tail = new;
    } 
    
}
void add_first(int val){
    node *new=creatnode(val);
    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        new->next = head;
        head = new;
    }  
}
void countElement(){
   int count=0;
    if(head==NULL){
     printf("list is empty");
    
     return;
    }
    node*temp=head;
    while (temp!=NULL)
    {
       count++;
       temp=temp->next;
    
    }
 printf("total no of element in list is :%d",count);
    
}



int main(){
add_first(2);
add_first(2);
add_first(2);
add_first(2);
countElement();

    return 0;
}