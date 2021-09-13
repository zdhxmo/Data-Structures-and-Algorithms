#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    // check column
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    // check upper left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;

        row--;
        col--;
    }

    //check upper right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;

        row--;
        col++;
    }

    return true;
}

bool nQueen(int **arr, int x, int n)
{
    // all queens have been placed - base case
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            // check for next row
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            arr[x][col] = 0; //backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter board size: ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}