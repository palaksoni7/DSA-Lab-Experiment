#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int v, e, i, src, dest;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    int adj[v][v];
    int visited[v];

    queue = (int*)malloc(v * sizeof(int));

    for (i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }

    printf("BFS Traversal: ");
    enqueue(0);
    visited[0] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < v; i++) {
            if (adj[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    free(queue);
    return 0;
}
