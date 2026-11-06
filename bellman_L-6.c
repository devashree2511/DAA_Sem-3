#include <stdio.h>

int main()
{
    int V, E;
    int u[20], v[20], w[20];
    int dist[10];
    int source;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter source destination weight:\n");

    for(int i = 0; i < E; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    printf("Enter source: ");
    scanf("%d", &source);

    for(int i = 0; i < V; i++)
        dist[i] = 999;

    dist[source] = 0;

    for(int i = 1; i < V; i++)
    {
        for(int j = 0; j < E; j++)
        {
            if(dist[u[j]] != 999 &&
               dist[u[j]] + w[j] < dist[v[j]])
            {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
    for(int j = 0; j < E; j++)
    {
        if(dist[u[j]] != 999 &&
           dist[u[j]] + w[j] < dist[v[j]])
        {
            printf("Negative cycle exists");
            return 0;
        }
    }

    printf("Vertex  Distance\n");

    for(int i = 0; i < V; i++)
        printf("%d       %d\n", i, dist[i]);

    return 0;
}