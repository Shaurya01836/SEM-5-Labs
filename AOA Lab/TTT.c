#include <stdio.h>

int main()
{
    int arr[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1},
    };

    int count = 0, x = 0, y = 0;
    while (count <= 9)
    {
        printf("Player 0 runs");
        scanf("%d %d", &x, &y);
        count++;
    }

    return 0;
}