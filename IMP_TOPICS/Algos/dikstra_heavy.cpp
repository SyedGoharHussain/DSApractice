#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

// ANSI escape codes for coloring
const string RESET = "\033[0m";
const string GREEN = "\033[32m";

// Function to find the minimum distance
int min(int dist[], bool sptSet[], int size)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < size; v++)
	{
		if (!sptSet[v] && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int grid[][10], int rows, int cols, int startRow, int startCol, int destRow, int destCol)
{
	int size = rows * cols;
	int dist[100]; // Maximum size for 10x10 grid
	bool sptSet[100] = {false};
	int parent[100]; // To store the shortest path

	for (int i = 0; i < size; i++)
	{
		dist[i] = INT_MAX;
		parent[i] = -1;
	}

	// Initialize the distance of the start node to its value
	dist[startRow * cols + startCol] = grid[startRow][startCol];

	for (int count = 0; count < size - 1; count++)
	{
		int u = min(dist, sptSet, size);
		sptSet[u] = true;

		int x = u / cols;
		int y = u % cols;

		// Explore neighbors
		for (int i = 0; i <= 1; i++)
		{
			int newX = x + (i == 0 ? 0 : 1);
			int newY = y + (i == 0 ? 1 : 0);

			if (newX < rows && newY < cols)
			{
				int newIndex = newX * cols + newY;
				if (!sptSet[newIndex] && dist[u] + grid[newX][newY] < dist[newIndex])
				{
					dist[newIndex] = dist[u] + grid[newX][newY];
					parent[newIndex] = u;
				}
			}
		}
	}

	// Print the distance and path
	int destIndex = destRow * cols + destCol;
	if (dist[destIndex] == INT_MAX)
	{
		cout << "No path found from (" << startRow << ", " << startCol << ") to (" << destRow << ", " << destCol << ")" << endl;
	}
	else
	{
		cout << "Minimum Time Required: " << dist[destIndex] << endl;

		// Print the path
		cout << "Shortest Path: ";
		for (int v = destIndex; v != -1; v = parent[v])
		{
			cout << "(" << v / cols << "," << v % cols << ") ";
		}
		cout << endl;

		// Display colored grid with highlighted path
		cout << "\nColored Grid:\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				bool isPathCell = false;
				// Check if this cell is part of the shortest path
				for (int v = destIndex; v != -1; v = parent[v])
				{
					if (v == (i * cols + j))
					{
						isPathCell = true;
						break;
					}
				}

				if (isPathCell)
				{
					cout << GREEN << setw(4) << grid[i][j] << RESET;
				}
				else
				{
					cout << setw(4) << grid[i][j];
				}
			}
			cout << endl;
		}
	}
}

int main()
{
	int rows, cols;

	cout << "Enter number of rows: ";
	cin >> rows;

	cout << "Enter number of columns: ";
	cin >> cols;

	int grid[10][10]; // Maximum size for a 10x10 grid

	cout << "Enter node values for each cell:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Value for cell (" << i << ", " << j << "): ";
			cin >> grid[i][j];
		}
	}

	cout << "\nGrid:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << grid[i][j];
		}
		cout << endl;
	}

	int startRow, startCol, destRow, destCol;

	cout << "Enter start row: ";
	cin >> startRow;

	cout << "Enter start column: ";
	cin >> startCol;

	cout << "Enter destination row: ";
	cin >> destRow;

	cout << "Enter destination column: ";
	cin >> destCol;

	// Validate input
	if (startRow < 0 || startRow >= rows || startCol < 0 || startCol >= cols || destRow < 0 || destRow >= rows || destCol < 0 || destCol >= cols)
	{
		cout << "Invalid start or destination coordinates." << endl;
		return 1;
	}

	dijkstra(grid, rows, cols, startRow, startCol, destRow, destCol);

	return 0;
}
