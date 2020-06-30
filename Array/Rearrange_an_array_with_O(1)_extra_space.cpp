/*
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. 

Input Format:
First-line contains an integer denoting the test cases 'T'. The first line of each test case contains an integer value depicting the size of array 'N' and the next line contains N space-separated integers denoting the elements of the array.

Output Format:
Print all elements of the array after rearranging, each separated by a space, in a separate line for each test case.

User Task:
The task is to complete the function arrange() which arranges the elements in the array. The printing is done automatically done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 107
0 <= Arr[i] < N

Example:
Input:
3
2
1 0
5
4 0 2 1 3
4
3 2 0 1

Output:
0 1
3 4 2 0 1
1 0 3 2
*/

#include <bits/stdc++.h>
using namespace std;

void arrange(long long arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] += n * (arr[arr[i]] % n);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / n;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        arrange(A, n);
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}