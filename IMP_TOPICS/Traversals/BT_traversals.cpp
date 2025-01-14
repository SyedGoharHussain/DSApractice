#include <iostream>
#define nullptr NULL
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a new node into the complete binary tree
Node* insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    // Insertion to the left side
    if (root->left == nullptr)
    {
        root->left = new Node(value);
    }
    // Insertion to the right side
    else if (root->right == nullptr)
    {
        root->right = new Node(value);
    }
    // If both sides are filled, we proceed to insert the node in the leftmost available position
    else
    {
        insert(root->left, value);
    }
    return root;
}

// BFS (Level Order) Traversal
void bfs(Node *root)
{
    if (root == nullptr)
        return;

    // Use a temporary array for level-order traversal
    Node *nodes[100];
    int front = 0, rear = 0;
    nodes[rear++] = root;

    while (front < rear)
    {
        Node *current = nodes[front++];
        cout << current->data << " ";

        if (current->left)
            nodes[rear++] = current->left;
        if (current->right)
            nodes[rear++] = current->right;
    }
}

// DFS Pre-order Traversal
void dfs_preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}

// DFS In-order Traversal
void dfs_inorder(Node *root)
{
    if (root == nullptr)
        return;

    dfs_inorder(root->left);
    cout << root->data << " ";
    dfs_inorder(root->right);
}

// DFS Post-order Traversal
void dfs_postorder(Node *root)
{
    if (root == nullptr)
        return;

    dfs_postorder(root->left);
    dfs_postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = nullptr;
    int n, value;

    cout << "Enter the number of nodes in the Complete Binary Tree: ";
    cin >> n;

    cout << "Enter the values to insert into the Complete Binary Tree:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (root == nullptr)
        {
            root = new Node(value);
        }
        else
        {
            insert(root, value);
        }
    }

    cout << "\nBFS Traversal (Level Order): ";
    bfs(root);
    cout << endl;

    cout << "DFS Pre-order Traversal: ";
    dfs_preorder(root);
    cout << endl;

    cout << "DFS In-order Traversal: ";
    dfs_inorder(root);
    cout << endl;

    cout << "DFS Post-order Traversal: ";
    dfs_postorder(root);
    cout << endl;

    return 0;
}

