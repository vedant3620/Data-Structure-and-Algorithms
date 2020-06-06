#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define test() ll t;cin>>t;while(t--)
#define MOD 1000000007
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

class Graph{
	int V;
	vector <int> *adj;
	public:
	Graph(int V){
		adj=new vector<int> [V];
		this->V=V;
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void printPath(int *pred,int dest){
		int n=dest;
		while(pred[n]!=-1){
			cout<<n<<" ";
			n=pred[n];
		}
	}
	void findShortestPath(int src,int dest){
		int pred[V];
		bool visited[V];
		for(int i=0;i<V;i++){
			pred[i]=-1;
			visited[i]=false;
		}
		queue <int> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty()){
			int a=q.front();
			q.pop();
			if(a==dest){
				printPath(pred,dest);
				return;
			}
			for(int i=0;i<adj[a].size();i++){
				if(visited[adj[a][i]]==false){
					q.push(adj[a][i]);
					pred[adj[a][i]]=a;
					visited[adj[a][i]]=true;
				}
			}
		}
		cout<<"No path"<<endl;
	}
};


int main() {
    SPEED;
    //CODE
	int V = 4; 
    Graph g(V); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
  
    int src = 0, dest = 3;
    g.findShortestPath(src, dest); 
	return 0;
}
