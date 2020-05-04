/*
Given two binary arrays arr1[] and arr2[] of same size n. Find length of the longest common span (i, j) where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j]. Elements are only 0 or 1.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains N space-separated integers B1, B2, ..., BN denoting the elements of the array.


Output:
In each seperated line output the maximum span with same sum.


Constraints:
1<=T<=31
1<=N<=100


Example:
Input:
1
6
0 1 0 0 0 0
1 0 1 0 0 1

Output:
4
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
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		for(ll i=0;i<n;i++){
		    ll t;
		    cin>>t;
		    a[i]-=t;
		}
		unordered_map <ll,ll> m;
		ll ans=0;
		ll sum=0;
		for(ll i=0;i<n;i++){
		    sum+=a[i];
		    if(sum==0)ans=max(ans,i+1);
		    else if(m.find(sum)!=m.end())ans=max(ans,i-m[sum]);
		    else m.insert(make_pair(sum,i));
		}
		cout<<ans<<endl;
	}
	return 0;
}