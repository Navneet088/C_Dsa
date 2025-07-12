#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;
Node *creatNode(int val){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
}
void preOrder(struct Node*root){
  if(root!=NULL){
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);

  }
}
void postOrder(struct Node*root){
    if(root!=NULL){
      
      preOrder(root->left);
      preOrder(root->right);
      printf("%d ",root->data);
  
    }
  }
  void inOrder(struct Node*root){
    if(root!=NULL){
      
      preOrder(root->left);
      printf("%d ",root->data);
      preOrder(root->right);
      
  
    }
  }

int main(){
Node*t1=creatNode(10);
Node*t2=creatNode(15);
Node*t3=creatNode(20);
t1->left=t2;
t1->right=t3;
printf("perOrder traversh\n");
preOrder(t1);
printf("\npostOrder traversh\n");
postOrder(t1);
printf("\nintOrder traversh\n");
inOrder(t1);





    return 0;
}