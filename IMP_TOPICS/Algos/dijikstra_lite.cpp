#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int graph[100][100], int n, int source, int destination) 
{
    int dist[100], visited[100] = {0};
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) 
	{
        int minDist = INF, u = -1;

        for (int v = 0; v < n; v++) 
        {
        	if (!visited[v] && dist[v] < minDist) 
			{
                minDist = dist[v];
                u = v;
            }	
		}
            

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) 
        {
        	if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) 
			{
                dist[v] = dist[u] + graph[u][v];
            }
		}
            
    }

    if (dist[destination] == INF) 
	{
        cout << "No path exists from " << source + 1 << " to " << destination + 1 << endl;
    } else 
	{
        cout << "Shortest distance from " << source + 1 << " to " << destination + 1 << " is " << dist[destination] << endl;
    }
}

int main() 
{
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    int graph[100][100] = {0};
    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < e; i++) 
	{
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w; 
    }

    int source, destination;
    cout << "Enter start vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    dijkstra(graph, n, source - 1, destination - 1);

    return 0;
}

