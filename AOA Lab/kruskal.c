#include <stdio.h>

int cost[9][9], parent[9];

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int i, j, a, b, u, v, n, ne = 1;
    int min, mincost = 0;

    printf("\n\n\tImplementation of Kruskal's Algorithm\n\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

// Implementation of Kruskal's Algorithm

// Enter the number of vertices: 4

// Enter the cost adjacency matrix:
// 0 10 6 5
// 10 0 0 15
// 6 0 0 4
// 5 15 4 0

// The edges of Minimum Cost Spanning Tree are:
// 1 edge (3,4) = 4
// 2 edge (4,1) = 5
// 3 edge (1,2) = 10

// Minimum cost = 19
