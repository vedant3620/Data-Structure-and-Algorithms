/*
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make two segments of lengths 3 and 2.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define reset(x) memset(dp,0,sizeof(x))
int main() {
    SPEED;
    //CODE
	test(){
		ll n;
		cin>>n;
		ll x,y,z;
		cin>>x>>y>>z;
		ll dp[n+1];
		reset(x);
		dp[0]=0;
		for(ll i=1;i<=n;i++){
		    dp[i]=INT_MIN;
		    if(i-x>=0){
		        dp[i]=max(dp[i],dp[i-x]+1);
		    }
		    if(i-y>=0){
		        dp[i]=max(dp[i],dp[i-y]+1);
		    }
		    if(i-z>=0){
		        dp[i]=max(dp[i],dp[i-z]+1);
		    }
		}
		cout<<dp[n]<<endl;
		
	}
	return 0;
}