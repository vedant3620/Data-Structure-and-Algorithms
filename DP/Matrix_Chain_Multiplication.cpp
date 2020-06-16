#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int ans = INT_MAX;
    for (k = i; k < j; k++)
    {
        int count = MatrixChainOrder(p, i, k) +
                    MatrixChainOrder(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];
        ans = min(ans, count);
    }
    return ans;
}
int mcm(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(m[i][j], q);
            }
        }
    }
    return m[1][n - 1];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1) << endl;
    cout << "Minimum number of multiplications is "
         << mcm(arr, n) << endl;

    return 0;
}