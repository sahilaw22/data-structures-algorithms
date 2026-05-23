#include <iostream>

/* Prim's MST using adjacency matrix. */
static const int MAX = 20;
static const int INF = 1000000;

int main() {
    int n;
    int graph[MAX][MAX];
    int selected[MAX];
    int parent[MAX];
    int key[MAX];

    std::cout << "Enter number of vertices (max " << MAX << "): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX) return 1;

    std::cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
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
    std::cout << "MST edges:\n";
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            std::cout << parent[v] << " - " << v << " : " << graph[parent[v]][v] << "\n";
            total += graph[parent[v]][v];
        }
    }
    std::cout << "Total cost: " << total << "\n";

    return 0;
}
