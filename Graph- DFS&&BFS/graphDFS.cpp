#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    public:
        Graph(int);
        void DFSUtility(int, bool[]);
        void DFS(int);
        void addEdge(int, int);
};
Graph::Graph(int n)
{
    V = n;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int vertex)
{
    bool visited[V];
    memset(visited, false, sizeof(visited));

    // To handle disconnected graph, we will call the DFSUtil function
    // on each node
    for(int i = 0; i < V; ++i)
        if(!visited[i])
            DFSUtility(i, visited);
}
void Graph::DFSUtility(int v, bool visited[])
{
    cout<<v<<' ';
    visited[v] = true;
    for(auto itr = adj[v].begin(); itr != adj[v].end(); ++itr)
    {
        if(!visited[*itr])
            DFSUtility(*itr, visited);
    }
}
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.DFS();    
    return 0;
}