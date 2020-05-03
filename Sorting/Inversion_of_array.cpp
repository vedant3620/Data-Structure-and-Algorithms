/*
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll ans=0;
void merge(ll a[],ll l,ll m,ll r){
    ll L[m-l+1],R[r-m];
    for(ll i=l;i<=m;i++)L[i-l]=a[i];
    for(ll i=m+1;i<=r;i++)R[i-m-1]=a[i];
    ll i=0,j=0,k=l;
    while(i<m-l+1&&j<r-m){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;k++;
        }
        else{
            ans+=(m-l+1-i);
            a[k]=R[j];
            k++;j++;
        }
    }
    while(i<m-l+1){
        a[k]=L[i];
        i++;k++;
    }
    while(j<r-m){
        a[k]=R[j];
        j++;k++;
    }
}
void mergeSort(ll a[],ll l,ll r){
    if(l<r){
        ll m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main() {
    SPEED;
    //CODE
	test(){
	    ans=0;
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];
		mergeSort(a,0,n-1);
		cout<<ans<<endl;
	}
	return 0;
}