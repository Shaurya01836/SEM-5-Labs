#include <stdio.h>
#include <conio.h>
#define INF 9999
#define MAX 10

int n;
int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];

void dijkstra(int src)
{
    int i, j, count, minDist, nextNode;

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < n - 1)
    {
        minDist = INF;

        // Find the next unvisited vertex with minimum distance
        for (i = 0; i < n; i++)
        {
            if (dist[i] < minDist && !visited[i])
            {
                minDist = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (minDist + cost[nextNode][i] < dist[i])
                {
                    dist[i] = minDist + cost[nextNode][i];
                }
            }
        }
        count++;
    }

    printf("\nShortest distances from source vertex %d:\n", src);
    for (i = 0; i < n; i++)
    {
        if (i != src)
            printf("Vertex %d → %d = %d\n", src, i, dist[i]);
    }
}

void main()
{
    int i, j, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (use 9999 for no direct edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nEnter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(src);

    getch();
}

// Enter the number of vertices: 5

// Enter the cost adjacency matrix (use 9999 for no direct edge):
// 0 10 9999 30 100
// 10 0 50 9999 9999
// 9999 50 0 20 10
// 30 9999 20 0 60
// 100 9999 10 60 0

// Enter the source vertex (0 to 4): 0

// Shortest distances from source vertex 0:
// Vertex 0 → 1 = 10
// Vertex 0 → 2 = 50
// Vertex 0 → 3 = 30
// Vertex 0 → 4 = 60
