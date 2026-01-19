#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[50];
int visited[50];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int v, e, i, src, dest;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    for (i = 0; i < v; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("DFS Traversal: ");
    DFS(0);

    return 0;
}
