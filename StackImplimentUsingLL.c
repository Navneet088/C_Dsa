#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node*link;

}node;
node* top=NULL;
void push(int x){
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;

}
void display(){
    struct node*temp;
    temp=top;
    if (top==NULL)
    {
     printf("stack is empty");
    }
    else{
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
             
        }
        
    }
    
}
void delete(){
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = top;
    int x = temp->data;
    top = top->link;  // update top to next node
    printf("Deleted Element: %d\n", x);
    free(temp);       // free the removed node
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Peeked element is: %d\n", top->data);
    }
}

int main (){
    push(1);
    push(10);  
    push(12);  push(13);  push(14);
    display();
    delete();
    display();
    peek();
   

    return 0;
}

