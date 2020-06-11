#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));

        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}

int min(int key[],bool mst[],int V){
    int minv=100001,min_index=-1;
    for(int i=0;i<V;i++){
        if(mst[i]==false&&minv>key[i]){
            minv=key[i];
            min_index=i;
        }
    }
    return min_index;
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int parent[V],key[V];
    bool mst[V];
    for(int i=0;i<V;i++){
        parent[i]=-1;
        key[i]=100001;
        mst[i]=false;
    }
    key[0]=0;
    for(int i=0;i<V-1;i++){
        int in=min(key,mst,V);
        mst[in]=true;
        for(int j=0;j<V;j++){
            if(mst[j]==false){
                if(key[j]>graph[in][j]){
                    key[j]=graph[in][j];
                    parent[j]=in;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<V;i++){
        ans+=graph[i][parent[i]];
    }
    return ans;
}
