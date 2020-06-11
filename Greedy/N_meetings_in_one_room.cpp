#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct item{
    ll in;
    ll start;
    ll finish;
};

bool comp(item a,item b){
    return a.finish<b.finish;
}

int main() {
    SPEED;
    //CODE
	test(){
		ll n;
		cin>>n;
		item arr[n];
		for(ll i=0;i<n;i++)arr[i].in=i+1;
		for(ll i=0;i<n;i++)cin>>arr[i].start;
		for(ll i=0;i<n;i++)cin>>arr[i].finish;
		sort(arr,arr+n,comp);
		ll ans=0;
		ll end=-1;
		for(ll i=0;i<n;i++){
		    if(arr[i].start>=end){
		        end=arr[i].finish;
		        cout<<arr[i].in<<" ";
		    }
		}
		cout<<endl;
	}
	return 0;
}
