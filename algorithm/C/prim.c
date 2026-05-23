#include <stdio.h>

/* Prim's MST using adjacency matrix. */
#define MAX 20
#define INF 1000000

int main(void) {
    int n;
    int graph[MAX][MAX];
    int selected[MAX];
    int parent[MAX];
    int key[MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        selected[i] = 0;
        key[i] = INF;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        for (int v = 0; v < n; v++) {
            if (!selected[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        selected[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!selected[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    printf("MST edges:\n");
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            printf("%d - %d : %d\n", parent[v], v, graph[parent[v]][v]);
            total += graph[parent[v]][v];
        }
    }
    printf("Total cost: %d\n", total);

    return 0;
}
