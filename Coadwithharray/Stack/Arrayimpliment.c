#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *arr;

};
int main(){
   struct Stack S;
   S.size=10;
   S.top=-1;
   S.arr=(int*)malloc(S.size*sizeof(int));
   

    return 0;
}