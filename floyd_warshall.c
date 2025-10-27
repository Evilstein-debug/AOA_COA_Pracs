#include <stdio.h>
#define INF 99999
#define MAX 100

void initialize_predecessor(int n, int pred[MAX][MAX], int dist[MAX][MAX]);
void floyd_warshall(int n, int dist[MAX][MAX], int pred[MAX][MAX]);
void print_path(int u, int v, int pred[MAX][MAX]);

int main() {
    int n;
    int dist[MAX][MAX];
    int pred[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    initialize_predecessor(n, pred, dist);
    floyd_warshall(n, dist, pred);

    printf("\nAll-pairs shortest distances:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest paths between all pairs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("Path from %d to %d: ", i + 1, j + 1);
                if (dist[i][j] == INF) {
                    printf("No path\n");
                } else {
                    print_path(i, j, pred);
                    printf("\n");
                }
            }
        }
    }

    return 0;
}

void initialize_predecessor(int n, int pred[MAX][MAX], int dist[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || dist[i][j] == INF)
                pred[i][j] = -1;
            else
                pred[i][j] = i;
        }
    }
}

void floyd_warshall(int n, int dist[MAX][MAX], int pred[MAX][MAX]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

void print_path(int u, int v, int pred[MAX][MAX]) {
    if (pred[u][v] == -1) {
        printf("%d ", v + 1);
        return;
    }
    print_path(u, pred[u][v], pred);
    printf("%d ", v + 1);
}
