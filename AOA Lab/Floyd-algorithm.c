// implement all pairs shortest paths problem using floyd's algorithm.

#include <stdio.h>
#include <conio.h>

int min(int, int);

void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 0; k <= n; k++)
    {
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void main()
{
    int p[10][10], w, n, e, u, v, i, j;
    printf("\n Enter the number of vertices : ");
    scanf("%d", &n);
    printf("\n Enter the number of edges : ");
    scanf("%d", &e);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            p[i][j] = 999;
    }

    for (i = 0; i <= e; i++)
    {
        printf("\n Enter the end vertices of edge %d with its weight \n", i);
        scanf("%d%d%d", &u, &v, &w);
        p[u][v] = w;
    }
    printf("\n Matrix of input data: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }
    floyds(p, n);
    printf("\n Transitive closure: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }
    printf("\n The shortest paths are: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j)
                printf(" <%d %d> = %d", i, j, p[i][j]);
        }
    }
}

//  Enter the number of vertices : 4

//  Enter the number of edges : 5

//  Enter the end vertices of edge 0 with its weight
// 1 2 3
//  Enter the end vertices of edge 1 with its weight
// 1 3 7
//  Enter the end vertices of edge 2 with its weight
// 2 4 2
//  Enter the end vertices of edge 3 with its weight
// 3 4 1
//  Enter the end vertices of edge 4 with its weight
// 4 1 6

//  Matrix of input data:
// 999     3       7       999
// 999     999     999     2
// 999     999     999     1
// 6       999     999     999

//  Transitive closure:
// 0       3       6       5
// 8       0       999     2
// 7       10      0       1
// 6       9       13      0

//  The shortest paths are:
//  <1 2> = 3 <1 3> = 6 <1 4> = 5 <2 1> = 8 <2 3> = 999 <2 4> = 2 <3 1> = 7 <3 2> = 10 <3 4> = 1 <4 1> = 6 <4 2> = 9 <4 3> = 13
