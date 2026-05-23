#include <iostream>

/* Kruskal's MST using edge list + simple union-find. */
static const int MAX = 20;

struct Edge {
    int u, v, w;
};

int findSet(int parent[], int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void unite(int parent[], int a, int b) {
    int ra = findSet(parent, a);
    int rb = findSet(parent, b);
    if (ra != rb) parent[rb] = ra;
}

int main() {
    int n;
    int graph[MAX][MAX];
    Edge edges[MAX * MAX];
    int ecount = 0;

    std::cout << "Enter number of vertices (max " << MAX << "): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX) return 1;

    std::cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[ecount++] = Edge{i, j, graph[i][j]};
            }
        }
    }

    for (int i = 0; i < ecount - 1; i++) {
        for (int j = 0; j < ecount - 1 - i; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0;
    int used = 0;
    std::cout << "MST edges:\n";
    for (int i = 0; i < ecount && used < n - 1; i++) {
        Edge e = edges[i];
        int ru = findSet(parent, e.u);
        int rv = findSet(parent, e.v);
        if (ru != rv) {
            unite(parent, ru, rv);
            std::cout << e.u << " - " << e.v << " : " << e.w << "\n";
            total += e.w;
            used++;
        }
    }
    std::cout << "Total cost: " << total << "\n";

    return 0;
}
