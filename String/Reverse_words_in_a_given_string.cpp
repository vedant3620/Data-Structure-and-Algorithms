/*
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test() ll t;cin>>t;while(t--)

int main()
 {
    test(){
        string s;
        cin>>s;
        vector <string> v;
        ll l=0;
        for(ll i=0;i<s.length();i++){
            if(s[i]=='.'){
                v.push_back(s.substr(l,i-l));
                l=i+1;
            }
        }
        v.push_back(s.substr(l,s.length()));
        reverse(v.begin(),v.end());
        for(ll i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1)cout<<".";
        }
        cout<<endl;
    }
	return 0;
}
