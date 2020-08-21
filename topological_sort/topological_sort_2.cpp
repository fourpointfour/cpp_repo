/*
 * Author: Vaibhav Kushwaha
 * Code: Topological Sort using inDegree based solution
 */
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int v);
        void addEdge(int u, int v);
        void topSort();
};
Graph::Graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::topSort()
{
    vector<int> inDegree(V, 0);
    for(int i = 0; i < V; ++i)
    {
        for(auto itr = adj[i].begin(); itr != adj[i].end(); ++itr)
        {
            inDegree[*itr]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < inDegree.size(); ++i)
        if(inDegree[i] == 0)
            q.push(i);
    vector<int> top_order;
    int c = 0;
    while(!q.empty())
    {
        int u = q.front();
        top_order.push_back(u);
        q.pop();
        for(auto itr = adj[u].begin(); itr != adj[u].end(); ++itr)
        {
            if(--inDegree[*itr] == 0)
                q.push(*itr);
        }
        ++c;
    }
    if(c != V)
    {
        cout<<"There's a cycle in the graph..."<<endl;
        return;
    }
    cout<<"The topological sort is:\n";
    for(int val : top_order)
        cout<<val<<' ';
    cout<<'\n';
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
    g.topSort();    
    return 0;
}
