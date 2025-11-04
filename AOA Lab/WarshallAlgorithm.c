// ex3 (b)

#include <stdio.h>

void warshalls(int path[10][10], int n);

int main()
{

    int path[10][10];
    int n, i, j;

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Error: Number of vertices must be between 1 and 10.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (1 if edge exists, 0 otherwise):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }

    printf("\nInitial Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", path[i][j]);
        }
        printf("\n");
    }

    warshalls(path, n);

    printf("\nTransitive Closure Matrix (1 means a path exists):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", path[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void warshalls(int path[10][10], int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {

                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }
}