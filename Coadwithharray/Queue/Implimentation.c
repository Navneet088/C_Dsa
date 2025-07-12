#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size;
    int f;
    int r;
    int*arr;

}Queue;
int  isEmpty(Queue *arr){
   if(arr->f==-1&&arr->r==-1){
    printf("Queue is empty\n");
    return 1;
    }
    return 0;
}
int isFull(Queue *q){
    if(q->r==q->size-1){
   
return 1;
     }
     return 0;
 }
 
void enqueue(int data,Queue *q){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else{
       
        q->r++;
        q->arr[q->r]=data;
        printf("%d enqueued to the queue\n", data);
    }
}
int dequeue(Queue *q){
    int a=0;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
       q->f++;
       
     a=q->arr[q->f];
    }
    printf("Deleted element of queue: %d\n",a);
    return a;
}

int main(){
Queue q;
q.size=4;
q.f=-1;
q.r=-1;
q.arr=(int*)malloc(q.size*sizeof(int));

enqueue(8,&q);
enqueue(12,&q);
enqueue(14,&q);
enqueue(16,&q);
dequeue(&q);
dequeue(&q);
enqueue(18,&q);



    return 0;
}
