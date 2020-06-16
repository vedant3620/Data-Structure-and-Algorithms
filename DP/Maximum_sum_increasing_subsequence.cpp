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

int msis(int arr[], int n)
{
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], arr[i] + dp[j]);
        }
    }
    return *max_element(dp, dp + n);
}

int main()
{
    SPEED;
    //CODE
    test()
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << msis(arr, n) << endl;
    }
    return 0;
}