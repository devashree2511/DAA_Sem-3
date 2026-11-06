#include <stdio.h>

int main()
{
    int n, graph[10][10];
    int visited[10] = {0};
    int min, x, y;
    int edges = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1;

    while(edges < n - 1)
    {
        min = 999;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] &&
                       graph[i][j] != 0 &&
                       graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", x, y, min);

        total += min;
        visited[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d", total);

    return 0;
}