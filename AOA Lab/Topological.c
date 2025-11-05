// Obtain the Topological ordering of vertices in a given digraph

#include <stdio.h>

int a[10][10], n, indegree[10];

void find_indegree()
{
    int j, i, sum;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += a[i][j];
        }
        indegree[j] = sum;
    }
}

void topology()
{
    int i, u, v, t[10], s[10], top = -1, k = 0;
    find_indegree();
    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            s[++top] = i;
    }
    while (top != -1)
    {
        u = s[top--];
        t[k++] = u;
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    s[++top] = v;
                }
            }
        }
    }

    printf("The topological sequence is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", t[i]);
}

void main()
{
    int i, j;
    printf("Enter number of jobs :");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    topology();
}

// Enter number of jobs :6

// Enter the adjacency matrix :
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 1 0 0
// 0 1 0 0 0 0
// 1 1 0 0 0 0
// 1 0 1 0 0 0
// The topological sequence is :
// 4 5 2 3 1 0
