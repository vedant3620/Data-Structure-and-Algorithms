/*
Given an array of n integers. The task is to remove or delete minimum number of elements from the array so that when the remaining elements are placed in the same sequence order form a sorted sequence.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:

Output the minimum number of deletions to make a sorted sequence. Print the answer in a new line.


Constraints:

1<= T <=100

1<= N <=1000

1<= A[ ] <=1000


Example:

Input:

1

5

5 6 1 7 4

Output:

2
*/

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

int lis(int arr[], int n)
{
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
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
        cout << (n - lis(arr, n)) << endl;
    }
    return 0;
}