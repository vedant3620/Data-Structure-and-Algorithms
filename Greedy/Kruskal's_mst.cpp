#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src, dest, weight;
};
class Graph
{
public:
    int V, E;
    Edge *edge;
};
Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph();
    graph->E = E;
    graph->V = V;
    graph->edge = new Edge[E];
    return graph;
}

class subset
{
public:
    int parent;
    int rank;
};
int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xset = find(subsets, x);
    int yset = find(subsets, y);

    if (subsets[xset].rank < subsets[yset].rank)
    {
        subsets[xset].parent = yset;
    }
    else if (subsets[xset].rank > subsets[yset].rank)
    {
        subsets[yset].parent = xset;
    }
    else
    {
        subsets[xset].parent = yset;
        subsets[xset].rank++;
    }
}
int comp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
void KruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    sort(graph->edge, graph->edge + graph->E, comp);
    subset *subsets = new subset[V];
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    return;
}

int main()
{
    /* Let us create following weighted graph  
            10  
        0--------1  
        | \ |  
    6| 5\ |15  
        | \ |  
        2--------3  
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}