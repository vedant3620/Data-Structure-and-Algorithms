#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

class Graph 
{ 
	    int V;     
	    vector<int> *adj; 
	    void topologicalSortUtil(int v, bool visited[],stack<int> &Stack); 
	public: 
	    Graph(int V);    
	    void addEdge(int v, int w); 
	    void topologicalSort(); 
};
Graph::Graph(int V){
	this->V=V;
	this->adj=new vector<int> [V];
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::topologicalSort(){
	stack <int> st;
	bool visited[V];
	memset(visited,false,V);
	for(int i=0;i<V;i++){
		if(!visited[i])topologicalSortUtil(i,visited,st);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &st){
	stack <int>s;
	s.push(v);
	while(!s.empty()){
		int a=s.top();
		s.pop();
		visited[a]=true;
		for(int i=0;i<adj[a].size();i++){
			if(!visited[adj[a][i]])topologicalSortUtil(adj[a][i],visited,st);
		}
		st.push(a);
	}
}

int main() 
{ 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 
  
    return 0; 
}
