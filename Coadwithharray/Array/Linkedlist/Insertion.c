#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct  Node* head;
    struct  Node*next;

    
   
};
void travsal(struct Node*ptr){
while (ptr!=NULL)
{
    printf("Element:%d\n",ptr->data);
    ptr=ptr->next;
}
  
}
struct Node *addfirst(struct Node *head ,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node * addinindex(struct Node *head ,int data,int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1){
    p=p->next;
    i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}
struct Node* addinlast(struct Node *head, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *addAfterNode(struct Node *head ,int data,struct Node *preNode){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=preNode->next;
    preNode->next=ptr;



}
int main(){
    struct  Node* head;
    struct  Node* second;
    struct  Node* third;
    struct  Node* four; 
    struct  Node* five;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node)); 
    head=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    four=(struct Node*)malloc(sizeof(struct Node));
    five=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=6;
    second->next=third;
    third->data=5;
    third->next=four;
    four->data=4;
    four ->next=five;
    five->data=3;
    five->next=NULL;
    
   head= addfirst(head,21);
    travsal(head);
    printf("\n");
head=addinindex(head,54,2);
travsal(head);
printf("\n");
head=addinlast(head,70);
travsal(head);
printf("\n");
head=addAfterNode(head,30,third);
travsal(head);
    return 0;
}