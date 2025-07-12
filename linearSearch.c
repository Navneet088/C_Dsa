//write a c program to find liner search using := 1 recurstion and  non recursion
#include<stdio.h>
int search(int arr[],int key,int size){
    for(int i=0; i<=size; i++){
        if(arr[i]==key){
            return i;
        }
        
    }
    return -1;
}

int usingRecSearch(int arr[], int size, int key, int i) {
    if (i > size) {
        return -1; 
    }
    if (arr[i] == key) {
        return i; 
    }
    return usingRecSearch(arr, size, key, i + 1); 
}
int rec(int arr[], int x, int n){
    if(arr[n-1]==x) return n-1;
    if(n==0) return 0;
    return rec(arr,x,n-1);
}
int main(){
    int arr[]={7,5,12,30,15,10};
    int key=10;
    int size=6;
    // printf("index of Key %d",search(arr,key,size));
    printf("index of Key %d\n",usingRecSearch(arr,size,key,0));
    printf("index of Key %d",rec(arr,key,size));

    return 0;
}