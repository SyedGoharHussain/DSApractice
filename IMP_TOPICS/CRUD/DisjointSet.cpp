#include <iostream>
using namespace std;

class DisjointSet
{
private:
    int *parent;
    int *rank;
    int *data;
    int size;

public:
    // Constructor to initialize the Disjoint Set with 'size' elements
    DisjointSet(int size)
    {
        this->size = size;
        parent = new int[size];
        rank = new int[size];
        data = new int[size];

        // Initially, each element is in its own set, so parent[i] = i
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0; // Rank is initially 0
            data[i] = i; // Initial data values are set to the element itself
        }
    }

    // Find with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by rank
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            // Union by rank: attach the smaller tree under the root of the larger tree
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++; // Increment rank if both trees have the same rank
            }
        }
    }

    // Insert operation: Insert an element into the set
    void insert(int x)
    {
        if (x >= size)
        {
            // Increase the size of arrays if the element exceeds the current size
            int newSize = x + 1;
            int *newParent = new int[newSize];
            int *newRank = new int[newSize];
            int *newData = new int[newSize];

            for (int i = 0; i < size; i++)
            {
                newParent[i] = parent[i];
                newRank[i] = rank[i];
                newData[i] = data[i];
            }

            for (int i = size; i < newSize; i++)
            {
                newParent[i] = i;
                newRank[i] = 0;
                newData[i] = i;
            }

            delete[] parent;
            delete[] rank;
            delete[] data;

            parent = newParent;
            rank = newRank;
            data = newData;

            size = newSize;
        }
    }

    // Delete operation: Removes an element (perform union with others)
    void deleteElement(int x)
    {
        if (x < size)
        {
            // Find the set of element x and union it with another element
            for (int i = 0; i < size; i++)
            {
                if (i != x)
                {
                    unionSets(x, i);
                }
            }
            // After union, we can treat the element as "deleted" by its new union with others
            parent[x] = -1; // Marking it as deleted (invalid)
        }
    }

    // Update operation: Change the data of an element (not the set structure)
    void update(int x, int newValue)
    {
        if (x < size)
        {
            data[x] = newValue;
        }
    }

    // Display the parent and rank arrays for debugging
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Element: " << i << " -> Parent: " << parent[i] << " Rank: " << rank[i] << " Data: " << data[i] << endl;
        }
    }

    // Destructor to free memory
    ~DisjointSet()
    {
        delete[] parent;
        delete[] rank;
        delete[] data;
    }
};

int main()
{
    int n, m, x, y, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    DisjointSet ds(n);

    cout << "Enter the number of union operations: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cout << "Enter the elements to union: ";
        cin >> x >> y;
        ds.unionSets(x, y);
    }

    // Inserting an element into the set
    cout << "Enter an element to insert: ";
    cin >> value;
    ds.insert(value);

    // Deleting an element from the set
    cout << "Enter an element to delete: ";
    cin >> value;
    ds.deleteElement(value);

    // Updating an element
    cout << "Enter an element to update: ";
    cin >> value;
    cout << "Enter the new value for element " << value << ": ";
    cin >> x;
    ds.update(value, x);

    // Display the updated set structure
    cout << "\nDisjoint Set after operations:\n";
    ds.display();

    return 0;
}
