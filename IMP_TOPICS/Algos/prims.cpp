#include <iostream>
using namespace std;

#define INF 100000 

void prims(int graph[100][100], int V)
{
    int parent[V];  
    int key[V];  
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int minKey = INF, u;
        for (int v = 0; v < V; v++)
        {
            if (!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - " << i + 1 << "\t" << graph[i][parent[i]] << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int graph[100][100] = {0};

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    prims(graph, V);

    return 0;
}

