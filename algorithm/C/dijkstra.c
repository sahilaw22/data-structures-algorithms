#include <stdio.h>

/* Dijkstra's shortest path using adjacency matrix. */
#define MAX 20
#define INF 1000000

int main(void) {
    int n;
    int graph[MAX][MAX];
    int dist[MAX];
    int visited[MAX];
    int src;

    printf("Enter number of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0) graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0..%d): ", n - 1);
    scanf("%d", &src);

    for (int i = 0; i < n; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
