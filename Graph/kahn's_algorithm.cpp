#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

class Graph{
	int V;
	vector <int> * adj;
	public:
		Graph(int V){
			this->V=V;
			this->adj=new vector <int>[V];
		}
		void addEdge(int v,int w){
			adj[v].push_back(w);
		}
		void topologicalSort(){
			vector <int> in(V,0);
			for(int i=0;i<V;i++){
				for(int j=0;j<adj[i].size();j++){
					in[adj[i][j]]++;
				}
			}
			queue <int> q;
			for(int i=0;i<V;i++){
				if(in[i]==0)q.push(i);
			}
			while(!q.empty()){
				int a=q.front();
				q.pop();
				cout<<a<<" ";
				for(int i=0;i<adj[a].size();i++){
					in[adj[a][i]]--;
					if(in[adj[a][i]]==0)q.push(adj[a][i]);
				}
			}
			
		}
};

int main() {
    SPEED;
    //CODE
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort(); 
	return 0;
}

