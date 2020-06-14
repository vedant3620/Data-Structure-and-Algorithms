#include <bits/stdc++.h>
using namespace std;
#define N 9
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int grid[N][N])
{
    unordered_map<int, int> row_[9], col_[9], box[3][3];
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            row_[row][grid[row][col]]++;
            col_[col][grid[row][col]]++;
            box[row / 3][col / 3][grid[row][col]] += 1;
            if (box[row / 3][col / 3][grid[row][col]] > 1 || col_[col][grid[row][col]] > 1 || row_[row][grid[row][col]] > 1)
            {
                return false;
            }
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N], int i, int j)
{
    if (i == N - 1 && j == N)
    {
        if (isSafe(grid))
        {
            printGrid(grid);
            return true;
        }
        return false;
    }
    if (j == N)
    {
        j = 0;
        i++;
    }
    if (grid[i][j] != 0)
    {
        return SolveSudoku(grid, i, j + 1);
    }
    for (int k = 1; k <= 9; k++)
    {
        grid[i][j] = k;
        if (SolveSudoku(grid, i, j + 1) == true)
            return true;
        grid[i][j] = 0;
    }
    return false;
}

int main()
{
    unordered_map<int, int> mp;
    mp[1]++;
    int grid[N][N] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                      {5, 2, 9, 1, 3, 4, 7, 6, 8},
                      {4, 8, 7, 6, 2, 9, 5, 3, 1},
                      {2, 6, 3, 0, 1, 5, 9, 8, 7},
                      {9, 7, 4, 8, 6, 0, 1, 2, 5},
                      {8, 5, 1, 7, 9, 2, 6, 4, 3},
                      {1, 3, 8, 0, 4, 7, 2, 0, 6},
                      {6, 9, 2, 3, 5, 1, 8, 7, 4},
                      {7, 4, 5, 0, 8, 6, 3, 1, 0}};
    if (SolveSudoku(grid, 0, 0) != true)
        cout << "No solution exists";

    return 0;
}