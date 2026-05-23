#include <stdio.h>

/* Kruskal's MST using edge list + simple union-find. */
#define MAX 20
#define INF 1000000

typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void unite(int parent[], int a, int b) {
    int ra = find(parent, a);
    int rb = find(parent, b);
    if (ra != rb) parent[rb] = ra;
}

int main(void) {
    int n;
    int graph[MAX][MAX];
    Edge edges[MAX * MAX];
    int ecount = 0;

    printf("Enter number of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[ecount++] = (Edge){i, j, graph[i][j]};
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
    printf("MST edges:\n");
    for (int i = 0; i < ecount && used < n - 1; i++) {
        Edge e = edges[i];
        int ru = find(parent, e.u);
        int rv = find(parent, e.v);
        if (ru != rv) {
            unite(parent, ru, rv);
            printf("%d - %d : %d\n", e.u, e.v, e.w);
            total += e.w;
            used++;
        }
    }
    printf("Total cost: %d\n", total);

    return 0;
}
