#include <iostream>

/* Dijkstra's shortest path using adjacency matrix. */
static const int MAX = 20;
static const int INF = 1000000;

int main() {
    int n;
    int graph[MAX][MAX];
    int dist[MAX];
    int visited[MAX];
    int src;

    std::cout << "Enter number of vertices (max " << MAX << "): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX) return 1;

    std::cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) graph[i][j] = INF;
        }
    }

    std::cout << "Enter source vertex (0.." << n - 1 << "): ";
    std::cin >> src;

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

    std::cout << "Shortest distances from " << src << ":\n";
    for (int i = 0; i < n; i++) {
        std::cout << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
