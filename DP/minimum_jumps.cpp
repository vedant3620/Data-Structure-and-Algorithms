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

int main()
{
    SPEED;
    //CODE
    test()
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll dp[n];
        for (ll i = 0; i < n; i++)
        {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (ll i = 0; i < n; i++)
        {
            if (dp[i] != INT_MAX)
            {
                for (ll j = 1; j <= a[i]; j++)
                {
                    if (j + i < n)
                    {
                        dp[j + i] = min(dp[j + i], 1 + dp[i]);
                    }
                }
            }
        }
        cout << (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]) << endl;
    }
    return 0;
}