#include <bits/stdc++.h>
using namespace std;

int lps(string s, int i, int j)
{
    if (i == j)
        return 1;
    if (s[i] == s[j] && j == i + 1)
        return 2;
    if (s[i] == s[j])
        return 2 + lps(s, i + 1, j - 1);
    return max(lps(s, i + 1, j), lps(s, i, j - 1));
}
int lps(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            if (s[i] == s[j] && l == 2)
            {
                dp[i][j] = 2;
            }
            else if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int LCS(string a, string b)
{
    int n = a.length();
    int m = b.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "GEEKS FOR GEEKS";
    int n = s.length();
    cout << lps(s, 0, n - 1) << endl;
    cout << lps(s) << endl;
    string t = s;
    reverse(t.begin(), t.end());
    cout << LCS(s, t) << endl;
    return 0;
}