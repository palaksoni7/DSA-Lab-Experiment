#include <stdio.h>
#define SIZE 10


int stack[SIZE];
int top = -1;


int isFull() {
    return top == SIZE - 1;
}


int isEmpty() {
    return top == -1;
}


void push(int num) {
    if (isFull()) {
        printf("Stack is Full!\n");
    } else {
        stack[++top] = num;
        printf("%d pushed\n", num);
    }
}


void pop() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
    } else {
        printf("%d popped\n", stack[top--]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, value;
    do {
        printf("\nStack Menu\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("-- Exited --\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);


    return 0;
}



