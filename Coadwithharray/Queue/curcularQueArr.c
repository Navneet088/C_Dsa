#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX];
int f=-1;
int r=-1;


void enque(){
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    if(r==MAX-1){
        printf("Queue is full!");

    }
    else if(f==-1&&r==-1){
        f=0;
        r=0;
      queue[r]=data;

    }
    else{
        r++;
        queue[r]=data;

    }

}
void deque(){
    
    if(f==-1&&r==-1){
        printf("Queue is Empty!");

    }
    else if(r==f){
        r=-1;
        f=-1;


    }
    else{
       
        printf("Deleted element: %d",queue[f]);
        f++;
        
    }

}
void display(){
    if(f==-1&&r==-1){
        printf("Queue is Empty!");

    }
    else {
        for(int i=f; i<=r; i++){
         printf("\nElement:%d",queue[i]);
        }
    }
}
void peek(){
    if(f==-1&&r==-1){
        printf("\nQueue is Empty!");

    }
    else{
        printf("\nPeeked Element:%d",queue[f]);
    }

}
int main(){
    int choice, flag = 1;

    while (flag) {
        printf("\n1- Insertion\n2- Deletion\n3- Display\n4- Peek\n5- Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enque(); break;
            case 2: deque(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: 
                printf("Exiting...\n");
                flag = 0; 
                break;
            default: 
                printf("Invalid choice\n");
        }
    }

    return 0;
}
