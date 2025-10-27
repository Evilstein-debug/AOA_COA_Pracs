#include <stdio.h>
#define INF 999999

int vertices;

void addEdge(int a[][10], int src, int des, int weight) {
    a[src][des] = weight;
    a[des][src] = weight;  // undirected
}

void initialise_matrix(int a[][10], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;
        }
    }
}

int min_path(int dist[], int visited[], int v) {
    int min = INF, min_index = -1;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[10][10], int src, int v) {
    int dist[10], visited[10], parent[10];

    for (int i = 0; i < v; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = min_path(dist, visited, v);
        if (u == -1) break; // no more reachable vertices
        visited[u] = 1;

        for (int w = 0; w < v; w++) {
            if (!visited[w] && graph[u][w] != INF && dist[u] + graph[u][w] < dist[w]) {
                dist[w] = dist[u] + graph[u][w];
                parent[w] = u;
            }
        }
    }

    printf("\nVertex\tDistance\tPath\n");
    for (int i = 0; i < v; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\t\tNo path\n", i);
        } else {
            printf("%d\t%d\t\t", i, dist[i]);

            // print path
            int stack[10], top = 0, node = i;
            while (node != -1) {
                stack[top++] = node;
                node = parent[node];
            }
            for (int j = top - 1; j >= 0; j--) {
                printf("%d ", stack[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int graph[10][10];
    int choice = 0, src, des, weight, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initialise_matrix(graph, vertices);

    while (choice != 3) {
        printf("\n1. Add Edge\n2. Run Dijkstra\n3. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source, destination, weight: ");
                scanf("%d %d %d", &src, &des, &weight);
                addEdge(graph, src - 1, des - 1, weight);
                break;
            case 2:
                printf("Enter the start vertex: ");
                scanf("%d", &start);
                dijkstra(graph, start - 1, vertices);
                break;
        }
    }

    return 0;
}
