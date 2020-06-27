#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void fillOrder(int v, bool visited[], stack<int> &Stack)
    {
        visited[v] = true;
        for (int a : adj[v])
        {
            if (!visited[a])
                fillOrder(a, visited, Stack);
        }
        Stack.push(v);
    }
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        for (int a : adj[v])
        {
            if (!visited[a])
            {
                DFSUtil(a, visited);
            }
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void printSCCs()
    {
        stack<int> S;
        bool *visited = new bool[V];
        memset(visited, false, V);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                fillOrder(i, visited, S);
        }
        Graph gr = getTranspose();
        for (int i = 0; i < V; i++)
            visited[i] = false;
        while (S.empty() == false)
        {
            int v = S.top();
            S.pop();
            if (visited[v] == false)
            {
                gr.DFSUtil(v, visited);
                cout << endl;
            }
        }
    }
    Graph getTranspose()
    {
        Graph g(V);
        for (int i = 0; i < V; i++)
        {
            for (int a : adj[i])
            {
                g.addEdge(a, i);
            }
        }
        return g;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    return 0;
}