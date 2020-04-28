/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
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
		stack <char> st;
		string s;
		cin>>s;
		ll flag=1;
		for(ll i=0;i<s.length();i++){
		    if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
		    else{
		        if(s[i]==')'){
		            if(!st.empty()&&st.top()=='(')st.pop();
		            else flag=0;
		        }
		        if(s[i]=='}'){
		            if(!st.empty()&&st.top()=='{')st.pop();
		            else flag=0;
		        }
		        if(s[i]==']'){
		            if(!st.empty()&&st.top()=='[')st.pop();
		            else flag=0;
		        }
		    }
		}
		if(flag&&st.empty())cout<<"balanced"<<endl;
		else cout<<"not balanced"<<endl;
	}
	return 0;
}