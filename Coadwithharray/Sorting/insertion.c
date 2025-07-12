#include<stdio.h>
void insertion(int arr[],int n){
    int key,j;
    for(int i=1; i<n; i++){
       key=arr[i];
       j=i-1;
       while (arr[j]>key&&j>=0){
         arr[j+1]=arr[j];
         j--;
       }
       arr[j + 1] = key; 
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
insertion(arr,n);
printf("\n");
print(arr,n);

    return 0;
}