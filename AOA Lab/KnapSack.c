#include <stdio.h>

int w[50], p[50], v[50][50], n, i, j, cap, x[50] = {0};

int max(int i, int j)
{
    return ((i > j) ? i : j);
}

int knap(int i, int j)
{
    int value;
    if (v[i][j] < 0)
    {

        if (j < w[i])
        {
            value = knap(i - 1, j);
        }
        else
        {

            value = max(knap(i - 1, j), p[i] + knap(i - 1, j - w[i]));
        }
        v[i][j] = value;
    }
    return (v[i][j]);
}

int main()
{
    int profit, count = 0;

    printf("\nEnter the number of elements\n");
    scanf("%d", &n);

    if (n >= 50)
    {
        printf("Error: Number of elements exceeds array limit of 50.\n");
        return 1;
    }

    printf("Enter the profit and weights of the elements\n");
    for (i = 1; i <= n; i++)
    {
        printf("For item no %d\n", i);
        scanf("%d%d", &p[i], &w[i]);
    }

    printf("\nEnter the capacity \n");
    scanf("%d", &cap);

    if (cap >= 50)
    {
        printf("Error: Capacity exceeds array limit of 50.\n");
        return 1;
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            if ((i == 0) || (j == 0))
            {
                v[i][j] = 0;
            }
            else
            {
                v[i][j] = -1;
            }
        }
    }

    profit = knap(n, cap);

    i = n;
    j = cap;
    while (j != 0 && i != 0)
    {
        if (v[i][j] != v[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
            i--;
        }
        else
        {
            i--;
        }
    }

    printf("\nItems included are\n");
    printf("Sl.no\tweight\tprofit\n");
    for (i = 1; i <= n; i++)
    {
        if (x[i])
        {
            printf("%d\t%d\t%d\n", ++count, w[i], p[i]);
        }
    }

    printf("Total profit = %d\n", profit);

    printf("\nPress Enter to exit...\n");
    getchar();
    getchar();

    return 0;
}

// Enter the number of elements
// 4
// Enter the profit and weights of the elements
// For item no 1
// 1 1
// For item no 2
// 2 3
// For item no 3
// 5 4
// For item no 4
// 6 5

// Enter the capacity
// 7

// Items included are
// Sl.no	weight	profit
// 1	4	5
// 2	3	2
// Total profit = 7

// Press Enter to exit...
