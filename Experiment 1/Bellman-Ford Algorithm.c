#include <stdio.h>

#define MAX 20
#define INFINITY 99999

void bellmanFord(int edges[MAX][3], int V, int E, int source) {
    int dist[MAX];
    int parent[MAX];
    int i, j;

    // Initialize
    for (i = 1; i <= V; i++) {
        dist[i] = INFINITY;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Relax edges V-1 times
    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INFINITY &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative cycle
    for (j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INFINITY &&
            dist[u] + w < dist[v]) {

            printf("Negative cycle detected\n");
            return;
        }
    }

    // Print result
    for (i = 1; i <= V; i++) {

        if (i == source)
            continue;

        if (dist[i] == INFINITY) {
            printf("%d INF None\n", i);
        }
        else {
            int path[MAX];
            int count = 0;
            int current = i;

            // Store path backwards
            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }

            printf("%d %d ", i, dist[i]);

            // Print path in correct order
            for (j = count - 1; j >= 0; j--) {
                printf("%d", path[j]);

                if (j != 0)
                    printf("->");
            }

            printf("\n");
        }
    }
}

int main() {
    int V, E;
    int edges[MAX][3];
    int source;
    int i;

    scanf("%d", &V);
    scanf("%d", &E);

    for (i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i][0],
              &edges[i][1],
              &edges[i][2]);
    }

    scanf("%d", &source);

    bellmanFord(edges, V, E, source);

    return 0;
}
