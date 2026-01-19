#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};


struct node *CreateNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct node *insertNode(struct node *node, int value) {
    if (node == NULL) {
        return CreateNode(value);
    }

    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } 
    else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }

    return node;
}


struct node *searchNode(struct node *node, int data) {
    if (node == NULL || node->key == data) {
        return node;
    }

    if (data < node->key) {
        return searchNode(node->left, data);
    } else {
        return searchNode(node->right, data);
    }
}


void inOrder(struct node *node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->key);
        inOrder(node->right);
    }
}


void preOrder(struct node *node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}


void postOrder(struct node *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->key);
    }
}


struct node *FindMin(struct node *node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}


struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node *temp = FindMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Delete Node\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("Inserted Successfully!\n");
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (searchNode(root, value) != NULL)
                printf("Value FOUND in BST.\n");
            else
                printf("Value NOT FOUND.\n");
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node Deleted (if existed).\n");
            break;

        case 4:
            printf("In-order Traversal: ");
            inOrder(root);
            printf("\n");
            break;

        case 5:
            printf("Pre-order Traversal: ");
            preOrder(root);
            printf("\n");
            break;

        case 6:
            printf("Post-order Traversal: ");
            postOrder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
