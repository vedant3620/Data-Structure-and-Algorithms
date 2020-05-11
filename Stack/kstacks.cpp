#include<bits/stdc++.h> 
using namespace std;

class kstacks{
	int *arr;
	int *next;
	int *top;
	int free;
	int n,k;
	
	public:
		kstacks(int n,int k);
		int pop(int sn);
		void push(int sn,int x);
		bool isFull(){  return (free==-1);  }
		bool isEmpty(int sn){	return (top[sn]==-1)	}
		
};

kstacks::kstacks(int n1,k1){
	arr =new int[n];
	next=new int[n];
	top =new int[k];
	
	for(int i=0;i<k;i++)top[i]=-1;
	for(int i=0;i<n-1;i++)next[i]=i+1;
}
kstacks::push(int sn,int x){
	if(isFull())cout<<"Overflow"<<endl;
	else{
		int i=free;
		free=next[i];
		next[i]=top[sn];
		top[sn]=i;
		arr[i]=x;
	}
}
kstacks::pop(int sn){
	if(isEmpty(sn)) {
		cout<<"Underflow"<<endl;
		return -1;
	}
	else{
		int i=top[sn];
		top[sn]=next[i];
		next[i]=free;
		free=i;
		return arr[i];
	}
}
