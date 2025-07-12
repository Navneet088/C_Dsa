#include <stdio.h>
#include <stdlib.h>

// Define the structure of Node
typedef struct Node {
  
    
    int data;

    struct Node *head;
    struct Node *next;
} Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void travsal( Node*ptr){
while (ptr!=NULL)
{
    printf("Element:%d\n",ptr->data);
    ptr=ptr->next;
}
  
}
 Node *addfirst(Node *head ,int data){
     Node *ptr=( Node*)malloc(sizeof( Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
 Node * addinindex( Node *head ,int data,int index){
     Node *ptr=( Node*)malloc(sizeof( Node));
    Node *p=head;
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
 Node* addinlast( Node *head, int data){
     Node *ptr=( Node*)malloc(sizeof( Node));
    ptr->data=data;
     Node *p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
 Node *addAfterNode( Node *head ,int data, Node *preNode){
     Node *ptr=( Node *)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=preNode->next;
    preNode->next=ptr;



}
int main() {
    Node *first = createNode(10);
    first->next = createNode(20);
    first->next->next = createNode(30);
    printf("Linked List: \n");
    travsal(first);
    first=addfirst(first,8);
    first=addinindex(first,110,2);
    first=addinlast(first,40);
    printf("after adding\n");
    travsal(first);

    return 0;
}