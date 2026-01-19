#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;
int count = 0;

void insertAtPosition(int position, int roll, char name[]);
void deleteAtPosition(int position);
void deleteByElement(int roll);
void searchNode(int roll);
void displayList(void);

void insertAtPosition(int position, int roll, char name[]) {
    if (position < 1 || position > count + 1) {
        printf("\nInvalid position! Current size: %d\n", count);
        return;
    }

    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Student *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    count++;
    printf("Node inserted successfully at position %d.\n", position);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("\nList is empty! Nothing to delete.\n");
        return;
    }

    if (position < 1 || position > count) {
        printf("\nInvalid position! Current size: %d\n", count);
        return;
    }

    struct Student *temp = head;

    if (position == 1) {
        head = temp->next;
        free(temp);
    } else {
        struct Student *prev = NULL;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

    count--;
    printf("Node deleted successfully from position %d.\n", position);
}

void deleteByElement(int roll) {
    if (head == NULL) {
        printf("\nList is empty! Nothing to delete.\n");
        return;
    }

    struct Student *temp = head, *prev = NULL;

    if (temp->roll == roll) {
        head = temp->next;
        free(temp);
        count--;
        printf("Node with Roll No %d deleted successfully.\n", roll);
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNode with Roll No %d not found.\n", roll);
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;
    printf("Node with Roll No %d deleted successfully.\n", roll);
}

void searchNode(int roll) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    struct Student *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\nNode Found at Position %d\n", position);
            printf("Roll No: %d\nName: %s\n", temp->roll, temp->name);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("\nNode with Roll No %d not found.\n", roll);
}

void displayList(void) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\n%-10s %-20s\n", "Roll No", "Name");

    struct Student *temp = head;
    while (temp != NULL) {
        printf("%-10d %-20s\n", temp->roll, temp->name);
        temp = temp->next;
    }

    printf("\nTotal Nodes: %d\n", count);
}

int main() {
    int choice, position, roll;
    char name[50];

    while (1) {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Insert Node at Position\n");
        printf("2. Delete Node by Position\n");
        printf("3. Delete Node by Roll No\n");
        printf("4. Search Node by Roll No\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\nInvalid input!\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter Roll No: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                insertAtPosition(position, roll, name);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 3:
                printf("Enter Roll No: ");
                scanf("%d", &roll);
                deleteByElement(roll);
                break;

            case 4:
                printf("Enter Roll No: ");
                scanf("%d", &roll);
                searchNode(roll);
                break;

            case 5:
                displayList();
                break;

            case 6:
                while (head != NULL) {
                    struct Student *tmp = head;
                    head = head->next;
                    free(tmp);
                }
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
