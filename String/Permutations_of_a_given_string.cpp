/*
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector <string> v;

void permute(string s,ll l,ll r){
    if(l==r)v.push_back(s);
    else{
        for(ll i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

int main() {
    SPEED;
    //CODE
	test(){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		ll n=s.length();
		permute(s,0,n-1);
		sort(v.begin(),v.end());
		for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";
		cout<<endl;
		v.clear();
	}
	return 0;
}