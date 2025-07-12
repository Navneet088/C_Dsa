#include<stdio.h>
void selectionSort(int arr[],int n){
    int min_idx, temp;
   for (int i = 0; i <n-1; i++)
   {  min_idx =i;

    for(int j=i+1; j<n; j++){
    if(arr[j]<arr[min_idx]){
       min_idx=j;
    }

   }
   int temp;
   temp=arr[min_idx];
  arr[min_idx]=arr[i];
  arr[i]=temp;
    
   }
   
}
void print(int arr[],int n){
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);

  } 
  printf("\n");
  
}
int main(){
int arr[]={4,9,3,7,10,12,2};
int n=sizeof(arr)/ sizeof(arr[0]);
print(arr,n);
selectionSort(arr,n);
print(arr,n);
return 0;
}
