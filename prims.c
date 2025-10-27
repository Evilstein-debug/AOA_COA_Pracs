#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 100
#define MAXE 1000

int vertices;
int graph[MAXV][MAXV];

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST() {
    if (vertices == 0) {
        printf("Graph is empty!\n");
        return;
    }
    int parent[MAXV], key[MAXV], mstSet[MAXV];
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet);
        if (u == -1) {
            printf("Graph is disconnected, MST not possible.\n");
            return;
        }
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    printf("\nEdges in MST:\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d\t%d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost of MST = %d\n", total);
}

int main() {
    int choice;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    while (1) {
        printf("\n1. Add edge\n2. Run Prim's Algorithm\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int u, v, w;
            printf("Enter edge (src dest weight): ");
            scanf("%d %d %d", &u, &v, &w);
            if (u < 1 || u > vertices || v < 1 || v > vertices || w <= 0) {
                printf("Invalid input!\n");
                continue;
            }
            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
            printf("Edge added!\n");
        }
        else if (choice == 2) {
            primMST();
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
