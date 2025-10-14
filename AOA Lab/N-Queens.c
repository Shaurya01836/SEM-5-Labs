#include <stdio.h>

int checkRow(int arr[8][8], int row, int col)
{
    for (int c = 0; c < 8; c++)
    {
        if (arr[row][c] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int checkCol(int arr[8][8], int row, int col)
{
    for (int r = 0; r < 8; r++)
    {
        if (arr[r][col] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int checkLeftDia(int arr[8][8], int row, int col)
{
    int diff = row - col;
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ((r - c) == diff && arr[r][c] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkRightDia(int arr[8][8], int row, int col)
{
    int sum = row + col;
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if ((r + c) == sum && arr[r][c] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int isSafe(int arr[8][8], int row, int col)
{
    return (checkLeftDia(arr, row, col) && checkRightDia(arr, row, col) && checkCol(arr, row, col) && checkRow(arr, row, col));
}

void backTrack(int arr[8][8], int row, int col)
{
    
}

int main()
{
    int arr[8][8] = {0};

    printf("First queen is placed at (0,0) \n");
    arr[0][0] = 1;

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (isSafe(arr, i, j))
            {
                arr[i][j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}