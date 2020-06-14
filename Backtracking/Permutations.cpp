#include <bits/stdc++.h>
using namespace std;

bool isSafe(string &str, int l, int i, int r)
{
    if (l != 0 && str[l - 1] == 'A' && str[i] == 'B')
    {
        return false;
    }
    if (r == l + 1 && str[i] == 'A' && str[l] == 'B')
        return false;
    return true;
}
void permute(string &str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        if (isSafe(str, l, i, r))
        {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}

int main()
{
    string str = "ABC";
    permute(str, 0, str.length() - 1);
    return 0;
}