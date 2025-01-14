#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Declare searchNode before it is used
Node *searchNode(Node *root, int value)
{
    if (root == nullptr)
        return nullptr;

    Node *queue[100]; // Simulating a queue with a fixed size
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *temp = queue[front++];
        if (temp->data == value)
            return temp;

        if (temp->left != nullptr)
            queue[rear++] = temp->left;
        if (temp->right != nullptr)
            queue[rear++] = temp->right;
    }
    return nullptr;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);

    Node *queue[100]; // Simulating a queue with a fixed size
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *temp = queue[front++];

        if (temp->left == nullptr)
        {
            temp->left = new Node(value);
            return root;
        }
        else
        {
            queue[rear++] = temp->left;
        }

        if (temp->right == nullptr)
        {
            temp->right = new Node(value);
            return root;
        }
        else
        {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
        return root;

    Node *queue[100]; // Simulating a queue with a fixed size
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node *nodeToDelete = nullptr;

    while (front < rear)
    {
        Node *temp = queue[front++];

        if (temp->data == value)
            nodeToDelete = temp;

        if (temp->left != nullptr)
            queue[rear++] = temp->left;
        if (temp->right != nullptr)
            queue[rear++] = temp->right;
    }

    if (nodeToDelete != nullptr)
    {
        nodeToDelete->data = queue[front - 1]->data; // Copy the last node's data to the node to delete
        delete (queue[front - 1]);                   // Remove the last node
    }
    return root;
}

Node *updateNode(Node *root, int oldValue, int newValue)
{
    Node *node = searchNode(root, oldValue); // searchNode should now be recognized
    if (node != nullptr)
    {
        node->data = newValue;
    }
    return root;
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    int n, value, oldValue, newValue;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the values to insert into the Binary Tree:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> value;
    root = deleteNode(root, value);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Enter old value to update: ";
    cin >> oldValue;
    cout << "Enter new value to update: ";
    cin >> newValue;
    root = updateNode(root, oldValue, newValue);

    cout << "Inorder after update: ";
    inorder(root);
    cout << endl;

    return 0;
}

