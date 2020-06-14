#include <bits/stdc++.h>
using namespace std;

int cutRodRec(int price[], int n)
{
    if (n <= 0)
        return 0;
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_val = max(price[i] + cutRodRec(price, n - i - 1), max_val);
    }
    return max_val;
}
int cutRod(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[i - j - 1] + price[j]);
        }
    }
    return dp[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRodRec(arr, size));
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    return 0;
}