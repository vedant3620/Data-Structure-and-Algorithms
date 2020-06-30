#include <bits/stdc++.h>
using namespace std;

int segregate(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}
int findUtil(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) <= n && arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}
int findMissing(int arr[], int n)
{
    int i = segregate(arr, n);
    return findUtil(arr + i, n - i);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << findMissing(arr, n) << endl;
    }
    return 0;
}