#include <iostream>

using namespace std;

struct Edge
{
    int u, v, weight;
};

// Bubble sort to replace std::sort
void bubbleSort(Edge edges[], int E)
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int findParent(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y)
{
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    if (xRoot != yRoot)
    {
        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

void kruskal(int V, int E, Edge edges[])
{
    bubbleSort(edges, E); // Sort edges using bubble sort

    int parent[V], rank[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge mst[E];
    int mstEdgeCount = 0;

    for (int i = 0; i < E && mstEdgeCount < V - 1; i++)
    {
        int uRoot = findParent(parent, edges[i].u);
        int vRoot = findParent(parent, edges[i].v);

        if (uRoot != vRoot)
        {
            mst[mstEdgeCount++] = edges[i];
            unionSets(parent, rank, uRoot, vRoot);
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 0; i < mstEdgeCount; i++)
    {
        cout << mst[i].u + 1 << " - " << mst[i].v + 1 << " : " << mst[i].weight << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[E];
    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; // Convert to 0-based index
        edges[i].v--; // Convert to 0-based index
    }

    kruskal(V, E, edges);
    return 0;
}

