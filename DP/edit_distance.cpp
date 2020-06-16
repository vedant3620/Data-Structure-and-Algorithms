#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c)
{
    return min(a, min(b, c));
}
int editDistanceRec(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (s1[m - 1] == s2[n - 1])
        return editDistanceRec(s1, s2, m - 1, n - 1);
    return 1 + min(editDistanceRec(s1, s2, m - 1, n - 1), //replace
                   editDistanceRec(s1, s2, m, n - 1),     //insert
                   editDistanceRec(s1, s2, m - 1, n));    //remove
}
int editDistance(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], //replace
                                   dp[i - 1][j],     //remove
                                   dp[i][j - 1]);    //insert
            }
        }
    }
    return dp[m][n];
}
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistanceRec(str1, str2, str1.length(), str2.length()) << endl;
    // cout << editDistance(str1, str2, str1.length(), str2.length()) << endl;

    return 0;
}