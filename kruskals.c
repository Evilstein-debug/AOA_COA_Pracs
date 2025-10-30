#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define MAXE 1000

struct Edge {
    int src, dest, weight;
};

int vertices, edges = 0;
struct Edge edgeList[MAXE];
int parent[MAXV];

int find(int i) {
    if (parent[i] == i) 
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int x, int y) {
    parent[find(x)] = find(y);
}

int cmp(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal() {
    if (edges == 0) {
        printf("No edges in graph!\n");
        return;
    }
    
    qsort(edgeList, edges, sizeof(struct Edge), cmp);
    
    for (int i = 0; i < vertices; i++) 
        parent[i] = i;
    
    int count = 0;
    printf("\nEdges in MST:\n");
    printf("Edge\tWeight\n");
    
    for (int i = 0; i < edges && count < vertices - 1; i++) {
        int u = edgeList[i].src;
        int v = edgeList[i].dest;
        
        if (find(u) != find(v)) {
            printf("%d - %d\t%d\n", u + 1, v + 1, edgeList[i].weight);
            unionSets(u, v);
            count++;
        }
    }
    
    if (count != vertices - 1) {
        printf("Graph is disconnected, MST not possible.\n");
    }
}

int main() {
    int choice;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    while (1) {
        printf("\n1. Add edge\n2. Run Kruskal\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (edges >= MAXE) {
                printf("Edge limit reached!\n");
                continue;
            }
            
            int u, v, w;
            printf("Enter edge (src dest weight): ");
            scanf("%d %d %d", &u, &v, &w);
            
            if (u < 1 || u > vertices || v < 1 || v > vertices) {
                printf("Invalid vertices! Must be 1..%d\n", vertices);
                continue;
            }
            
            edgeList[edges].src = u - 1;
            edgeList[edges].dest = v - 1;
            edgeList[edges].weight = w;
            edges++;
            
        } else if (choice == 2) {
            kruskal();
            
        } else if (choice == 3) {
            break;
            
        } else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}