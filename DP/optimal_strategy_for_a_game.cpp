#include <bits/stdc++.h>
using namespace std;
int x;
int optimalStrategyRec(int arr[], int l, int r)
{
    x++;
    if (l == r)
        return arr[l];
    if (l + 1 == r)
        return max(arr[l], arr[r]);
    return max(arr[l] + min(optimalStrategyRec(arr, l + 2, r), optimalStrategyRec(arr, l + 1, r - 1)),
               arr[r] + min(optimalStrategyRec(arr, l + 1, r - 1), optimalStrategyRec(arr, l, r - 2)));
}
int optimalStrategy(int arr[], int n)
{
    int table[n][n];
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            int x = (i + 2 <= j) ? table[i + 2][j] : 0;
            int y = (i + 1 <= j - 1) ? table[i + 1][j - 1] : 0;
            int z = (i <= j - 2) ? table[i][j - 2] : 0;
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
}
int memo[100][100];
int optMemo(int arr[], int l, int r)
{
    if (l == r)
        return arr[l];
    if (l + 1 == r)
        return max(arr[l], arr[r]);
    if (memo[l][r] != -1)
        return memo[l][r];
    return max(arr[l] + min(optMemo(arr, l + 2, r), optMemo(arr, l + 1, r - 1)),
               arr[r] + min(optMemo(arr, l + 1, r - 1), optMemo(arr, l, r - 2)));
}
int optimalStrategyMemo(int arr[], int n)
{
    memset(memo, -1, sizeof(memo));
    return optMemo(arr, 0, n - 1);
}

int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);
    return max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
               (sum - oSRec(arr, i, j - 1, sum - arr[j])));
}

int optimalStrategyOfGame(int *arr, int n)
{
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);
    return oSRec(arr, 0, n - 1, sum);
}
int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);
    if (memo[i][j] != -1)
        return memo[i][j];
    memo[i][j] = max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
                     (sum - oSRec(arr, i, j - 1, sum - arr[j])));

    return memo[i][j];
}
int optimalStrategyOfGame(int *arr, int n)
{
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);
    memset(memo, -1, sizeof(memo));
    return oSRec(arr, 0, n - 1, sum);
}
int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("%d\n", optimalStrategyRec(arr1, 0, n - 1));
    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyRec(arr2, 0, n - 1));
    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyRec(arr3, 0, n - 1));

    n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategy(arr1, n));
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategy(arr2, n));
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategy(arr3, n));

    n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyMemo(arr1, n));
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyMemo(arr2, n));
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyMemo(arr3, n));

    return 0;
}