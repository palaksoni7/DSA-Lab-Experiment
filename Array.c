#include <stdio.h>
#define size 10


int arr[size];
int n = 0;  


int isEmpty() {
    return n == 0;
}


void display() {
    if (isEmpty()) {
        printf("Array is Empty!\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}


void insert(int pos, int value) {
    if (n == size) {
        printf("Array is Full!\n");
        return;
    }
    if (pos < 1 || pos > n + 1) {
        printf("Invalid Position!\n");
        return;
    }
    // shift elements to right
    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    n++;
    printf("%d inserted at position %d\n", value, pos);
}


void delete(int pos) {
    if (isEmpty()) {
        printf("Array is Empty!\n");
        return;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid Position!\n");
        return;
    }
    printf("%d deleted from position %d\n", arr[pos - 1], pos);
    // shift elements to left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}


void sortArray() {
    if (isEmpty()) {
        printf("Array is Empty! Cannot sort.\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}


void update(int pos, int value) {
    if (isEmpty()) {
        printf("Array is Empty!\n");
        return;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid Position!\n");
        return;
    }
    printf("Value at position %d updated from %d to %d\n", pos, arr[pos - 1], value);
    arr[pos - 1] = value;
}


int main() {
    int choice, pos, value;
    do {
        printf("\n--- Array Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Update\n4. Display\n5. Sort\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(pos, value);
                break;
            case 2:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                printf("Enter position to update (1 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(pos, value);
                break;
            case 4:
                display();
                break;
            case 5:
                sortArray();
                break;
            case 6:
                printf("--Exited--\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 6);


    return 0;
}



