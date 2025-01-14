#include <iostream>
using namespace std;

#define MAX_VERTICES 10

class Graph
{
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix

public:
    Graph(int V);
    void addEdge(int v, int w);
    void deleteEdge(int v, int w);
    void updateEdge(int v, int oldW, int newW);
    void display();
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int v, int w)
{
    adj[v][w] = 1;
    adj[w][v] = 1;
}

void Graph::deleteEdge(int v, int w)
{
    adj[v][w] = 0;
    adj[w][v] = 0;
}

void Graph::updateEdge(int v, int oldW, int newW)
{
    deleteEdge(v, oldW);
    addEdge(v, newW);
}

void Graph::display()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E, v, w;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges (v, w):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cout << "Graph after adding edges:\n";
    g.display();

    cout << "Enter edge to delete (v, w): ";
    cin >> v >> w;
    g.deleteEdge(v, w);

    cout << "Graph after deletion:\n";
    g.display();

    cout << "Enter edge to update (v, oldW, newW): ";
    cin >> v >> w >> w;
    g.updateEdge(v, w, w);

    cout << "Graph after updating:\n";
    g.display();

    return 0;
}

