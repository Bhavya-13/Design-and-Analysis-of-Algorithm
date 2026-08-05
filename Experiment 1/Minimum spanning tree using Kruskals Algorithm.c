#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void kruskalMST(int **cost, int V)
{
    int parent[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge = 0;
    int minCost = 0;

    while (edge < V - 1 && V>=1 && V<=100)
    {
        int min = INT_MAX;
        int a = -1, b = -1;

        // Find minimum edge
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        // Find root of a
        int u = a;
        while (parent[u] != u)
            u = parent[u];

        // Find root of b
        int v = b;
        while (parent[v] != v)
            v = parent[v];

        if (u != v)
        {
            printf("Edge %d:(%d, %d) cost:%d\n", edge, a, b, min);
            minCost += min;
            edge++;
            parent[u] = v;
        }

        // Remove the selected edge
        cost[a][b] = cost[b][a] = INT_MAX;
    }

    printf("Minimum cost= %d\n", minCost);
}
int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
