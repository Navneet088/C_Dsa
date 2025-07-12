#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int f=-1;
int r=-1;


void enque(){
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    if((r + 1) % MAX == f){
        printf("Queue is full!");

    }
    else if(f==-1&&r==-1){
        f=0;
        r=0;
      queue[r]=data;

    }
    else{
        r = (r + 1) % MAX;  
        queue[r] = data;

    }

}
void dequeue() {
    if (f == -1 && r == -1) {
        printf("Queue is Empty!\n");
    } else if (f == r) {
        printf("Deleted element: %d\n", queue[f]);
        f = r = -1;  // Reset queue after last element deletion
    } else {
        printf("Deleted element: %d\n", queue[f]);
        f = (f + 1) % MAX;  // Circular increment
    }
}

void display() {
    if (f == -1 && r == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue Elements: ");
    int i = f;
    while (1) {
        printf("%d ", queue[i]);
        if (i == r)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
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
    // int choice, flag = 1;

    // while (flag) {
    //     printf("\n1- Insertion\n2- Deletion\n3- Display\n4- Peek\n5- Exit\n");
    //     printf("Enter a choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1: enque(); break;
    //         case 2: deque(); break;
    //         case 3: display(); break;
    //         case 4: peek(); break;
    //         case 5: 
    //             printf("Exiting...\n");
    //             flag = 0; 
    //             break;
    //         default: 
    //             printf("Invalid choice\n");
    //     }
    // }
  
    enque();enque();enque();enque();enque();
    display();
    dequeue();dequeue(); dequeue();
    enque();enque();enque();
    display();
   

    return 0;
}
