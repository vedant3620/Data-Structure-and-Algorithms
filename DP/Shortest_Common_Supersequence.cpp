#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() \
    ll t;      \
    cin >> t;  \
    while (t--)
#define MOD 1000000007
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)

ll LCS(string s1, string s2)
{
    ll m = s1.length();
    ll n = s2.length();
    ll dp[m + 1][n + 1];
    for (ll i = 0; i <= m; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    SPEED;
    //CODE
    test()
    {
        string a, b;
        cin >> a >> b;
        cout << (a.length() + b.length() - LCS(a, b)) << endl;
    }
    return 0;
}