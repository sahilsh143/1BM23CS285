#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear =-1;
void enqueue(int x){
    if(rear==N-1){
        printf("over flow\n");
    }
    else if (rear==-1 && front==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("underflow\n");
    }
    else if(front==rear){
        printf("%d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d\n",queue[front]);
        front++;
    }
}
void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("empty\n");
    }
    else{
        for(i=front;i<rear+1;i++){
            printf("%d",queue[i]);
        }
    }
}
int main(){
    int task,a;
    task=0;
    while(task!=4){
        printf("press 1 to enqueue\n");
        printf("press 2 to dequeue\n");
        printf("press 3 to display\n");
        printf("press 4 to exit\n");
        scanf("%d",&task);
        switch(task){
            case 1: printf("enter a number");
                   scanf("%d",&a);
                   enqueue(a);
                   break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("exit");
                    break;
        }

    }
}
