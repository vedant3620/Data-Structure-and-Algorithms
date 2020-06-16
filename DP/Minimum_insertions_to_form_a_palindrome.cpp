#include <bits/stdc++.h>
using namespace std;

int minIns(string s, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (l == r)
        return 0;
    if (l + 1 == r)
        return s[l] == s[r] ? 0 : 1;
    return s[l] == s[r]
               ? minIns(s, l + 1, r - 1)
               : (min(minIns(s, l + 1, r), minIns(s, l, r - 1)) + 1);
}
int findMinInsertions(string str, int n)
{
    int table[n][n], l, h, gap;
    memset(table, 0, sizeof(table));

    for (int gap = 1; gap < n; gap++)
    {
        for (int l = 0, h = gap; h < n; l++, h++)
        {
            table[l][h] = (str[l] == str[h]) ? table[l + 1][h - 1] : (1 + min(table[l + 1][h], table[l][h - 1]));
        }
    }
    return table[0][n - 1];
}
int lcs(string X, string Y, int m, int n)
{
    int L[n + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void reverseStr(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int findMinInsertionsLCS(string str, int n)
{
    string rev = "";
    rev = str;
    reverseStr(rev);
    return (n - lcs(str, rev, n, n));
}
int main()
{
    string str = "geeks";
    cout << minIns(str, 0, str.length() - 1) << endl;
    cout << findMinInsertions(str, str.length()) << endl;
    cout << findMinInsertionsLCS(str, str.length()) << endl;
    return 0;
}