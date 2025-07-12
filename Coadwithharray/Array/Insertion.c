#include<stdio.h>
void display(int arr[], int n){//n=index of element
    for(int i=0; i<=n; i++){
        printf("\t%d",arr[i]);
    }
    printf("\n");
}
int incert(int arr[],int size, int element, int capacity,int index){
    if(size>=capacity){
        return -1;
    }
    else{
        for(int i=size-1; i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=element;
        return 1;
    }
}

int main()
{
    int arr[12] = {7, 8, 12, 27, 88};
    int size = 4, element = 45, index = 0;
    display(arr, size);
    size += 1;
 incert(arr, size,element,12, index);
    display(arr, size);
    return 0;
}
