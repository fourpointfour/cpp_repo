#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    public:
        Graph(int v);
        void addEdge(int u, int v);
        void BFS(int v);
};
Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::BFS(int v)
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty())
    {
        int vertex = q.front();
        cout<<vertex<<' ';
        q.pop();
        for(auto itr = adj[vertex].begin(); itr != adj[vertex].end(); ++itr)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
    cout<<'\n';
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
    g.BFS(0);
    return 0;
}