#include <bits/stdc++.h>
using namespace std;
int minCoins(int S[], int m, int V)
{
    if (V == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (S[i] <= V)
        {
            int sub_res = minCoins(S, m, V - S[i]);
            if (sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    return res;
}
int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}