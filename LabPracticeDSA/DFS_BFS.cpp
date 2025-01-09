#include <iostream>
#include <queue>
#include <stack>
#include <string> // For student name
using namespace std;

// Structure to hold student information
struct Student {
    string name;
    int rollNo;
    float gpa;
};

// Class representing the tree
class Tree {
private:
    int adjMatrix[100][100]; // Adjacency matrix (static size limit: 100 nodes)
    int nodes;               // Number of nodes in the tree
    Student studentData[100]; // Array to store information of each node

public:
    // Constructor to initialize the tree
    Tree(int n) {
        nodes = n;
        for (int i = 0; i <= nodes; ++i) {
            for (int j = 0; j <= nodes; ++j) {
                adjMatrix[i][j] = 0; // Initialize adjacency matrix to 0
            }
        }
    }

    // Function to add an edge between two nodes
    void addEdge(int u, int v) {
        adjMatrix[u][v] += 1; // Increment to account for multiple edges
        adjMatrix[v][u] += 1; // Since it's an undirected tree
    }

    // Function to add student information to a node
    void addStudentInfo(int node, const string& name, int rollNo, float gpa) {
        studentData[node].name = name;
        studentData[node].rollNo = rollNo;
        studentData[node].gpa = gpa;
    }

    // Function to display adjacency matrix
    void displayMatrix() const {
        cout << "Adjacency Matrix of the Tree:\n";
        for (int i = 1; i <= nodes; ++i) {
            for (int j = 1; j <= nodes; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to display student information for each node
    void displayStudentInfo() const {
        cout << "Student Information for each node:\n";
        for (int i = 1; i <= nodes; ++i) {
            cout << "Node " << i << ": "
                 << "Name: " << studentData[i].name << ", "
                 << "Roll No: " << studentData[i].rollNo << ", "
                 << "GPA: " << studentData[i].gpa << endl;
        }
    }

    // BFS traversal
    void bfs(int startNode) const {
        bool visited[100] = {false}; // Track visited nodes
        queue<int> q;

        // Start BFS from the given node
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal:\n";
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Print student info for the current node
            cout << "Visited Node " << current << ": "
                 << "Name: " << studentData[current].name << ", "
                 << "Roll No: " << studentData[current].rollNo << ", "
                 << "GPA: " << studentData[current].gpa << endl;

            // Traverse all neighbors
            for (int i = 1; i <= nodes; ++i) {
                if (adjMatrix[current][i] > 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    // DFS traversal
    void dfs(int startNode) const {
        bool visited[100] = {false}; // Track visited nodes
        stack<int> s;

        // Start DFS from the given node
        s.push(startNode);

        cout << "DFS Traversal:\n";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            // If not visited, visit the node
            if (!visited[current]) {
                visited[current] = true;

                // Print student info for the current node
                cout << "Visited Node " << current << ": "
                     << "Name: " << studentData[current].name << ", "
                     << "Roll No: " << studentData[current].rollNo << ", "
                     << "GPA: " << studentData[current].gpa << endl;
            }

            // Traverse all neighbors in reverse order (to simulate recursion stack behavior)
            for (int i = nodes; i >= 1; --i) {
                if (adjMatrix[current][i] > 0 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
};

int main() {
    int n, edges;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    Tree tree(n);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    // Input student information for each node
    for (int i = 1; i <= n; ++i) {
        string name;
        int rollNo;
        float gpa;
        cout << "Enter student info for node " << i << " (Name RollNo GPA): ";
        cin >> name >> rollNo >> gpa;
        tree.addStudentInfo(i, name, rollNo, gpa);
    }

    tree.displayMatrix();
    tree.displayStudentInfo();

    int startNode;
    cout << "Enter the starting node for BFS and DFS: ";
    cin >> startNode;

    tree.bfs(startNode);
    tree.dfs(startNode);

    return 0;
}
