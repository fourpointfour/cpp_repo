/*
 * Author: Vaibhav Kushwaha
 * Code: Topological Sort using regular approach
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
        void topSortUtil(int val, bool visited[], stack<int> &st);
};
Graph::Graph(int v)
{
    this->V = v;
    this->adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::topSort()
{
    stack<int> st;
    bool visited[V];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < V; ++i)
        if(!visited[i])
            topSortUtil(i, visited, st);
    cout<<"\nThe topological sort is:\n";
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
}
void Graph::topSortUtil(int v, bool visited[], stack<int>& st)
{
    visited[v] = true;
    for(auto itr = adj[v].begin(); itr != adj[v].end(); ++itr)
    {
        if(!visited[*itr])
            topSortUtil(*itr, visited, st);
    }
    st.push(v);
}
int main()
{
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(4, 0);
    g.topSort();
    return 0;
}