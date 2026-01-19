#include<stdio.h>
#define size 10
 
int queue[size];
int front = -1, rear = -1;
 
int isFull(){
    if(rear == size - 1){
        return 1;
    }
   return 0;
}
int isEmpty(){
    if(front == -1 || front > rear){
        return 1;
    }
    return 0;
}
 
void insert(int num){
    if(isFull()){
        printf("Queue is full\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        queue[++rear] = num;
        printf("Successfully Inserted\n");
    }
}
 
void delete(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        printf("%d deleted\n",queue[front]);
        front++;
    }
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty");
    }
    else{
        printf("Queue elements are :");
        for(int i = front; i<=rear ; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
 
int main(){
    int choice,value;
    do{
        printf("Queue Menu\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&choice);
 
        switch(choice){
            case 1:
            printf("Enter element to insert :");
            scanf("%d",&value);
            insert(value);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("--Exited--");
            break;
            default:
            printf("Invalid Choice\n");
        }
    }
    while(choice != 4);
 
    return 0;
}


