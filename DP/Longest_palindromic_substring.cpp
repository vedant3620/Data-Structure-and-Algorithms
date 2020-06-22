#include <bits/stdc++.h>
using namespace std;

void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

int lpsubstring(string s)
{
    int n = s.length();
    bool table[n][n];
    memset(table, false, sizeof(table));
    for (int i = 0; i < n; i++)
        table[i][i] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            table[i][i + 1] = true;
    }
    int begin = 0, maxlength = 1;

    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;
                if (maxlength < len)
                {
                    maxlength = len;
                    begin = i;
                }
            }
        }
    }
    cout << s.substr(begin, maxlength) << endl;
    return maxlength;
}
int longestPalSubstr(string str)
{
    int maxLength = 1;
    int start = 0;
    int len = str.length();
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
    return maxLength;
}
int main()
{
    string str = "forgeeksskeegfor";
    cout << "Length is: " << lpsubstring(str);
    return 0;
}