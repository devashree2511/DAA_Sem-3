#include <stdio.h>

int main()
{
    int n, cost[10][10];
    int parent[10];
    int min, a, b, u, v;
    int edges = 1, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        parent[i] = 0;

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    while(edges < n)
    {
        min = 999;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while(parent[u])
            u = parent[u];

        while(parent[v])
            v = parent[v];

        if(u != v)
        {
            printf("%d - %d = %d\n", a, b, min);

            total += min;
            parent[v] = u;
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d", total);

    return 0;
}