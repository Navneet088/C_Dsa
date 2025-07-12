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
struct Node *deletFirst(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
struct Node *deletAtindex(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
   for (int  i = 0; i < index-1; i++)
   {
    p=p->next;
    q=q->next;
   }
   p->next=q->next;
   free(q);
    
    return head;

}
struct Node *deletAtlast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;

    }

   p->next=NULL;
   free(q);
    
    return head;

}
//deleting the given value
struct Node *deletgivenValue(struct Node *head,int value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value&&q->next!=NULL){
        p=p->next;
        q=q->next;

    }
if(q->data==value){
    p->next=q->next;
    free(q);
} 
    return head;

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
    printf("befor delition\n");
travsal(head);

   
    printf("after delition\n");
    // travsal(deletAtindex(head,2));
    // travsal(deletAtlast(head));
    travsal(deletgivenValue(head,3));
   
    return 0;
}