/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)


/* SOLUTION 1 */
int main() {
    SPEED;
    //CODE
	test(){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		ll ans[n];
		stack <ll> st;
		st.push(0);
		for(ll i=1;i<n;i++){
		    while(!st.empty()&&a[i]>a[st.top()]){
		        ans[st.top()]=a[i];
		        st.pop();
		    }
		    st.push(i);
		}
		while(!st.empty()){ans[st.top()]=-1;st.pop();}
		for(ll i=0;i<n;i++)cout<<ans[i]<<" ";
		cout<<endl;
		
	}
	return 0;
}

/* SOLUTION 2 */

int main() {
    SPEED;
    //CODE
	test(){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)cin>>a[i];
		ll ans[n];
		stack <ll> st;
		for(ll i=n-1;i>=0;i--){
		    while(!st.empty()&&a[st.top()]<a[i])st.pop();
		    if(st.empty())ans[i]=-1;
		    else ans[i]=a[st.top()];
		    st.push(i);
		}
		for(ll i=0;i<n;i++)cout<<ans[i]<<" ";
		cout<<endl;
		
	}
	return 0;
}
