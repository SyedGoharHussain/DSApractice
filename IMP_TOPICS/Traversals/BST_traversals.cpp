#include <iostream>
#include <queue>
#include <stack>
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

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void bfs(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
    cout << endl;
}

void dfs_preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}

void dfs_inorder(Node *root)
{
    if (root == nullptr)
        return;

    dfs_inorder(root->left);
    cout << root->data << " ";
    dfs_inorder(root->right);
}

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

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    cout << "Enter the values to insert into the BST:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBFS Traversal (Level Order): ";
    bfs(root);

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

