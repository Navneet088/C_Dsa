#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node*right;
    int height;


}node;
struct node *root=NULL;
int getheight(node*root){
    if(root==NULL){
        return 0;

    }
    return root->height;
}
struct node * creatNode(int val){
    node*new =(node*)malloc(sizeof(node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    new->height=1;

    return new;

}
int getblanceFactor(node* root){
    if(root==NULL){
        return 0;

    }
    return getheight(root->left)-getheight(root->right);

}
node *leftRotate(node*y){
    node *x=y->left;
    node *t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return x;
}
node *rightRotate(node*x){
    node *y=x->left;
    node *t2=y->right;
    y->left=x;
    y->right=t2;

    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return y;
} 

int main(){
    return 0;
}