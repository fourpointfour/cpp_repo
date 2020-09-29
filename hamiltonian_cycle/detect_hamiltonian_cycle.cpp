#include<bits/stdc++.h>
using namespace std;
// check whether its safe to add vertex v to the path
bool isSafe(vector< vector<int> > graph, vector<int> path, int pos, int v)
{
    if(graph[path[pos-1]][v] == 0)
        return false;
    for(int i = 0; i < pos; ++i)
    {
        if(path[i] == v)
            return false;
    }
    return true;
}
bool HamiltonianPath(vector< vector<int> > graph, vector<int> path, int pos)
{
    if(pos == graph.size())
    {
        if(graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int v = 1; v < graph.size(); ++v)
    {
        if(isSafe(graph, path, pos, v))
        {
            path[pos] = v;
            if(HamiltonianPath(graph, path, pos+1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E, u, v;
        cin>>V>>E;
        vector< vector<int> > graph(V, vector<int>(V, 0));
        for(int e = 0; e < E; ++e)
        {
            cin>>u>>v;
            graph[u-1][v-1] = 1;
            graph[v-1][u-1] = 1;
        }
        // cout<<"The given graph is:\n";
        // for(int i = 0; i < graph.size(); ++i)
        // {
        //     for(int j = 0; j < graph.size(); ++j)
        //         cout<<graph[i][j]<<' ';
        //     cout<<endl;
        // }
        vector<int> path(V, -1);
        path[0] = 0;
        if(HamiltonianPath(graph, path, 1))
            cout<<"Hamiltonian Path present!\n";
        else
            cout<<"Hamiltonian Path not present!\n";
    }
    return 0;
}