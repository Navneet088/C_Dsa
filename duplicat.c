#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n){
    int temp;
for(int i=0; i<n; i++){
    for(int j=0; j<n-i-1; j++)
    {
       if(arr[j]>arr[j+1]){
         temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;

       }
    }
}
}
void print (int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}

int main(){

int arr[]={1,0,1,0,0,2,1,1,2,0,1};
int n = sizeof(arr) / sizeof(arr[0]);
sort(arr,n);
print(arr,n);


    return 0;
}