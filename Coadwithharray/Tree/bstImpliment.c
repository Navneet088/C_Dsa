#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;
Node*t=NULL;
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
      
      postOrder(root->left);
      postOrder(root->right);
      printf("%d ",root->data);
  
    }
  }
  void inOrder(struct Node*root){
    if(root!=NULL){
      
      inOrder(root->left);
      printf("%d ",root->data);
      inOrder(root->right);
      
  
    }
  }
  //recursive call
Node*search(Node*root,int key){
  if(root==NULL){
    return NULL;
  }
  if(root->data==key){
    return root;
  }
  else if(root->data>key){
    return search(root->left,key);
  }
  else{
    return search(root->right,key);
  }

}
//itretive call
Node *searchInt(Node*root,int key){
  while(root!=NULL){
    if(root->data==key){
      return root;
    }
    else if(key<root->data){
      root=root->left;
    }
    else{
      root=root->right;
    }

  }
  return NULL;
}
//incertion element in BST
Node* incert(Node*root,int val){
  Node*prev=NULL;
  Node*new=creatNode(val);
  while(root!=NULL){
    prev=root;
    if(root->data==val){
      return;
    }
   else if(val<root->data){
    root=root->left;
   }else{
    root=root->right;
   }
  }
  if(val<prev->data){
    prev->left=new;
  }else{
    prev->right=new;
  }
}
//delet a node in BST
Node *delete(Node*root,int val){
  if(val<root->data){
    delete(root->left,val);
  }
  else  if(val>root->data){
    delete(root->right,val);
  }
  else{
      
  }
}
int main(){
Node*t=creatNode(5);
Node*t1=creatNode(3);
Node*t2=creatNode(6);
Node*t3=creatNode(1);
Node*t4=creatNode(4);
t->left=t1;
t->right=t2;
t1->left=t3;
t1->right=t4;
incert(t,10);




printf("perOrder traversh\n");
preOrder(t);
printf("\npostOrder traversh\n");
postOrder(t);
printf("\nintOrder traversh\n");
inOrder(t);
printf("\n");
//  struct Node* n=search(t,10);
//  if(n!=NULL){
// printf("search element:%d",n->data);
//  }else{
//   printf("element is not found");
//  }printf("\n");
//  struct Node* p=searchInt(t,1);
//  if(p!=NULL){
// printf("search element:%d",p->data);
//  }else{
//   printf("element is not found");
//  }

 return 0;
}