#include <stdio.h>

int main()
{
    int n, graph[10][10];
    int dist[10], visited[10] = {0};
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source: ");
    scanf("%d", &source);

    for(int i = 0; i < n; i++)
        dist[i] = 999;

    dist[source] = 0;

    for(int count = 0; count < n; count++)
    {
        int min = 999;
        int u = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] != 0 &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex  Distance\n");

    for(int i = 0; i < n; i++)
        printf("%d       %d\n", i, dist[i]);
