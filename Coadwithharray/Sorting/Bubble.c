#include<stdio.h>
void bubble(int arr[],int n){
 
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
 
    for (int  i = 0; i <n; i++)
    {
    printf("%d ",arr[i]);
    }
    
}
int main(){
int arr[]={4,9,3,7,10,12,2};
int n=sizeof(arr)/ sizeof(arr[0]);
print(arr,n);
bubble(arr,n);
printf("\n");
print(arr,n);

    return 0;
}