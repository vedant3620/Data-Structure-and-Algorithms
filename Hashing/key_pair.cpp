/*
Given an array A of N positive integers and another number X. Determine whether or not there exist two elements in A whose sum is exactly X.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N and X, N is the size of array. The second line of each test case contains N integers representing array elements A[i].

Output:
Print "Yes" if there exist two elements in A whose sum is exactly X, else "No" (without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
Yes
Yes

Explanation:
Testcases 1: 10 and 6 are numbers making a pair whose sum is equal to 16.
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
		ll n,s;
		cin>>n>>s;
		ll a[n];
	    for(ll i=0;i<n;i++)cin>>a[i];
	    bool ans=false;
	    unordered_map <ll,ll> m;
	    for(ll i=0;i<n;i++){
	        if(m.find(s-a[i])==m.end()){
	            m[a[i]]++;
	        }
	        else{
	            ans=true;
	            break;
	        }
	    }
	    if(ans)cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}