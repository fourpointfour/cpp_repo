#include<bits/stdc++.h>
using namespace std;

#define V 9

int minIndex(bool visited[], int dist[])
{
    int mini = INT_MAX, min_index;
    for(int i = 0; i < V; ++i)
    {
        if(!visited[i] && dist[i] <= mini)
        {
            mini = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printGraph(int dist[])
{
    cout<<"Vertex \t\tDistance from source\n";
    for(int i = 0; i < V; ++i)
    {
        cout<<i<<" \t\t\t"<<dist[i]<<'\n';
    }
}

void dijkstra(int src, int graph[V][V])
{
    bool visited[V];
    int dist[V];
    // for(int v = 0; v < V; ++v)
    // {
    //     visited[v] = false;
    //     dist[v] = INT_MAX;
    // }
    memset(visited, false, sizeof(visited));
    memset(dist, INT_MAX, sizeof(dist));
    dist[src] = 0;

    for(int count = 0; count < V - 1; ++count)
    {
        int u = minIndex(visited, dist);

        visited[u] = true;

        for(int v = 0; v < V; ++v)
        {
            if(!visited[v] && graph[u][v] && (dist[u] != INT_MAX) &&
               (dist[u] + graph[u][v] < dist[v]))
               dist[v] = dist[u] + graph[u][v];
        }
    }
    printGraph(dist);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(0, graph);
    return 0;
}