#include <stdio.h>

int cost[10][10];
int visited[10];
int n;

int main()
{
    int i, j, a, b;
    int ne = 1;
    int min, mincost = 0;

    printf("\n\n\tImplementation of Prim's Algorithm\n\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    visited[1] = 1;
    for (i = 2; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (ne < n)
    {
        min = 999;
        a = 1;
        b = 1;

        for (i = 1; i <= n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 1; j <= n; j++)
                {

                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (visited[b] == 0)
        {
            printf("%d edge (%d,%d) = %d\n", ne, a, b, min);
            mincost += min;
            visited[b] = 1;
            ne++;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

// Implementation of Prim's Algorithm

// Enter the number of vertices: 4

// Enter the cost adjacency matrix:
// 0 10 6 5
// 10 0 0 15
// 6 0 0 4
// 5 15 4 0

// The edges of Minimum Cost Spanning Tree are:
// 1 edge (1,4) = 5
// 2 edge (4,3) = 4
// 3 edge (1,2) = 10

// Minimum cost = 19
