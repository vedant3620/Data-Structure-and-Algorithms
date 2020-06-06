/*
Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, denoting number of elements in array and at most k positions away from its target position respectively. Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56
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
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
		    cin>>a[i];
		}
		priority_queue<int,vector<int>,greater<int> > pq;
		ll z=0;
		for(int i=0;i<k;i++)pq.push(a[i]);
		for(int i=k;i<n;i++){
		    a[z]=pq.top();
		    pq.pop();
		    pq.push(a[i]);
		    z++;
		}
		while(!pq.empty()){
		    a[z]=pq.top();
		    pq.pop();
		    z++;
		}
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}