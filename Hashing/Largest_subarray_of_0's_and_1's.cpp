/*
Given an array of 0's and 1's your task is to complete the function maxLen which returns size of the largest sub array with equal number of 0's and 1's. The function maxLen takes 2 arguments. The first argument is the array A[] and second argument is the size 'N' of the array A[].

Input:
The first line of the input is T denoting the number of test cases. Then T test cases follow . Each test case contains two lines. The first line of each test case is a number N denoting the size of the array and in the next line are N space separated values of A [].

Output:
For each test case output in a new line the max length of the subarray.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= A[] <= 1

Example:
Input
2
4
0 1 0 1
5
0 0 1 0 0

Output
4
2

Explanation:
Testacase 1: The array from index [0...3] contains equal number of 0's and 1's. Thus maximum length of subarray having equal number of 0's and 1's is 4.
*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}

int maxLen(int arr[], int n) {
    
    unordered_map <int,int> m;
    int ans=0;
    int sum=0;
    m.insert(make_pair(0,-1));
    for(int i=0;i<n;i++){
        if(arr[i]==1)sum++;
        else sum--;
        if(m.find(sum)==m.end()){
            m.insert(make_pair(sum,i));
        }
        else{
            ans=max(ans,i-m[sum]);
        }
    }
    return ans;

}