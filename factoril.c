#include<stdio.h>
int factorial(int n){
    if(n<=1){
        return 1;
    }
   
    return factorial(n-1)*n;
}
int main(){
    int n;
    printf("ENTER the number");
    scanf("%d",&n);
    printf("%d\t",factorial(n));
    return 0;
}
