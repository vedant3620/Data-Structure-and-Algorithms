#include <bits/stdc++.h>
using namespace std;
//Recursive Soln
int count(int S[], int m, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <= 0 && n >= 1)
        return 0;
    return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
}
//DP solution O(nm) space complexity
int countDP1(int S[], int m, int n)
{
    int i, j, x, y;
    int table[n + 1][m];
    for (i = 0; i < m; i++)
        table[0][i] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}
//DP solution O(nm) space complexity
int countDP2(int S[], int m, int n)
{
    int i, j, x, y;
    int table[m][n + 1];
    for (i = 0; i < m; i++)
        table[i][0] = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            x = (j - S[i] >= 0) ? table[i][j - S[i]] : 0;
            y = (i >= 1) ? table[i - 1][j] : 0;
            table[i][j] = x + y;
        }
    }
    return table[m - 1][n];
}

//DP solution O(n) space complexity
int countDP3(int S[], int m, int n)
{
    int table[n + 1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = S[i]; j <= n; j++)
        {
            table[j] += table[j - S[i]];
        }
    }
    return table[n];
}

int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", count(arr, m, 4));
    printf("%d\n", countDP1(arr, m, 4));
    printf("%d\n", countDP2(arr, m, 4));
    printf("%d\n", countDP3(arr, m, 4));
    return 0;
}