/*
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input: 
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case contains a value of n. 

Output: 
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n <=1000

Example:
Input:
2
9
4

Output:
2
2
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
	    ll n;
	    cin>>n;
	    ll dp[n+1];
	    dp[1]=0;
	    for(ll i=2;i<=n;i++){
	        dp[i]=INT_MAX;
	    }
	    for(ll i=1;i<n;i++){
	        for(ll j=3*i;j<=n;j*=3){
	            dp[j]=min(dp[j],dp[j/3]+1);
	        }
	        dp[i+1]=min(dp[i]+1,dp[i+1]);
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}