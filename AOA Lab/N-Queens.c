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
    int r, c;

    for (r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (arr[r][c] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int checkRightDia(int arr[8][8], int row, int col)
{
    int r, c;

    for (r = row, c = col; r < 8 && c >= 0; r++, c--)
    {
        if (arr[r][c] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int isSafe(int arr[8][8], int row, int col)
{
    return (checkLeftDia(arr, row, col) && checkRightDia(arr, row, col) && checkCol(arr, row, col) && checkRow(arr, row, col));
}

int solveNQueens(int arr[8][8], int col)
{
    if (col >= 8)
        return 1;

    for (int i = 0; i < 8; i++)
    {
        if (isSafe(arr, i, col))
        {
            arr[i][col] = 1;

            if (solveNQueens(arr, col + 1))
                return 1;

            arr[i][col] = 0; // backtrack
        }
    }
    return 0;
}

int main()
{
    int arr[8][8] = {0};

    printf("Solving N Queens using backtrack\n");

    if (solveNQueens(arr, 0))
    {
        printf("Solution found:\n");
    }
    else
    {
        printf("No solution exists.\n");
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
