#include<stdio.h>

int search(int number[],int key, int size){
    int start=0; 
    int end=size;
while(start<=end){
    int mid=(start+end)/2;
    if(number[mid]==key){
        return mid;
    }
    if(number[mid]<key){
        start=mid+1;
    }
    else{
        end=mid-1;
    }
}    

return -1;     
    }

int main(){
    int number[]={4,5,8,6,3,14,12};
   int key=14;
   int size=7;
 printf("index of Key %d",search(number,key,size));
    return 0;
}