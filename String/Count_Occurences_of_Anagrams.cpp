/*
Given a word S and a text C. Return the count of the occurences of anagrams of the word in the text.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a text S consisting of only lowercase characters.
The second line contains a word consisting of only lowercase characters.

Output:
Print the count of the occurences of anagrams of the word C in the text S.

Constraints:
1 <= T <= 50
1 <= |S| <= |C| <= 50

Example:
Input:
2
forxxorfxdofr
for
aabaabaa
aaba

Output:
3
4

Explaination:
for, orf and ofr appears in the first test case and hence answer is 3.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll check(ll a[],ll b[]){
    for(ll i=0;i<26;i++) if(a[i]!=b[i]) return 0;
    return 1;
}

int main() {
    SPEED;
    //CODE
	test(){
		ll a[26]={0},b[26]={0};
		string s1,s2;
		cin>>s1>>s2;
		for(ll i=0;i<s2.length();i++){
		    b[s2[i]-'a']++;
		}
		if(s1.length()<s2.length()){
		    cout<<0<<endl;
		    continue;
		}
		for(ll i=0;i<s2.length();i++){
		    a[s1[i]-'a']++;
		}
		ll ans=check(a,b);
		for(ll i=s2.length();i<s1.length();i++){
		    a[s1[i]-'a']++;
		    a[s1[i-s2.length()]-'a']--;
		    ans+=check(a,b);
		}
		cout<<ans<<endl;
	}
	return 0;
}