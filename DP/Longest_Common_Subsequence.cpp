/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
    SPEED;
    //CODE
	test(){
		ll n,m;
		cin>>n>>m;
		string s1,s2;
		cin>>s1>>s2;
		ll dp[n+1][m+1];
		for(ll i=0;i<=n;i++){
		    for(ll j=0;j<=m;j++){
		        if(i==0||j==0)dp[i][j]=0;
		        else{
		            if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
		            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		        }
		    }
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}