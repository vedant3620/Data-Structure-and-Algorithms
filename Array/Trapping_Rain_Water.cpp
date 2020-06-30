/*
Given an array arr[] of N non-negative integers representing the height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
The structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.



Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space-separated numbers to be stored in the array.

Output:
Output the total unit of water trapped in between the blocks.

User Task:
The task is to complete the function trappingWater() which returns the total amount of water that can be trapped.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by the block of height 4 is 3 units, block of height 0 is 7 units. So, the total unit of water trapped is 10 units.
*/

#include <bits/stdc++.h>

using namespace std;

//O(n) time and O(1) space complexity
int trappingWater(int arr[], int n)
{

    // Your code here
    int i = 0, j = n - 1;
    int lmax = arr[0], rmax = arr[j];
    int ans = 0;
    while (i <= j)
    {
        int l = arr[i], r = arr[j];
        lmax = max(lmax, arr[i]);
        rmax = max(rmax, arr[j]);
        if (l > r)
        {
            ans += min(lmax, rmax) - arr[j];
            j--;
        }
        else
        {
            ans += min(lmax, rmax) - arr[i];
            i++;
        }
    }
    return ans;
}

//O(n) time and O(n) space complexity

int trappingWater(int arr[], int n)
{
    int l[n], r[n];
    l[0] = arr[0];
    r[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        l[i] = max(l[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(l[i], r[i]) - arr[i]);
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << trappingWater(a, n) << endl;
    }

    return 0;
}