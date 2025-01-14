#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void addedge(int graph[][100], int from, int to)
{
    graph[from][to] = 1; 
    graph[to][from] = 1;
}

void bfs(int graph[][100], int v, int start)
{
    queue<int> q;
    bool visited[100] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 1; i <= v; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void dfs(int graph[][100], int v, int start)
{
    stack<int> s;
    bool visited[100] = {false};

    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";

    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        cout << current << " ";

        for (int i = v; i >= 1; i--)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void dfs_preorder(int graph[][100], int v, int start, bool visited[])
{
    visited[start] = true;
    cout << start << " ";

    for (int i = 1; i <= v; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs_preorder(graph, v, i, visited);
        }
    }
}

void dfs_postorder(int graph[][100], int v, int start, bool visited[])
{
    visited[start] = true;

    for (int i = 1; i <= v; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs_postorder(graph, v, i, visited);
        }
    }
    cout << start << " ";
}

void dfs_inorder(int graph[][100], int v, int start, bool visited[])
{
    visited[start] = true;

    bool leftVisited = false;

    for (int i = 1; i <= v && !leftVisited; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs_inorder(graph, v, i, visited);
            leftVisited = true;
        }
    }

    cout << start << " ";

    for (int i = 1; i <= v; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs_inorder(graph, v, i, visited);
            break; 
        }
    }
}

void display(int graph[][100], int v)
{
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    int graph[100][100] = {0}; // Initialize adjacency matrix to zero

    for (int i = 1; i <= e; i++)
    {
        int from, to;

        cout << "\n--------------------------\n";
        cout << "Edge No " << i << endl;
        cout << "From node: ";
        cin >> from;
        cout << "To node: ";
        cin >> to;

        if (from >= 1 && from <= v && to >= 1 && to <= v)
        {
            addedge(graph, from, to);
        }
        else
        {
            cout << "Invalid edge! Please enter vertices between 1 and " << v << ".\n";
            i--;
        }
    }

    int start;
    cout << "\nEnter start node: ";
    cin >> start;

    // BFS Traversal
    cout << "\nBFS Traversal: ";
    bfs(graph, v, start);

    // DFS Traversal
    cout << "\nDFS Traversal: ";
    dfs(graph, v, start);

    bool visited[100] = {false};
    
    cout << "\n\nPre-order DFS Traversal: ";
    dfs_preorder(graph, v, start, visited);

    fill(visited, visited + 100, false);
    cout << "\n\nPost-order DFS Traversal: ";
    dfs_postorder(graph, v, start, visited);

    fill(visited, visited + 100, false);
    cout << "\n\nIn-order DFS Traversal: ";
    dfs_inorder(graph, v, start, visited);

    cout << "\n\nAdjacency Matrix:\n";
    display(graph, v);

    return 0;
}

