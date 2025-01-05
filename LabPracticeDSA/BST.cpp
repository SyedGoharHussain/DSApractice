#include <iostream>
using namespace std;

class node 
{
	public:
	    int data;
	    node* left;
	    node* right;
	
	    node() : left(NULL), right(NULL) {}
	    node(int val) : data(val), left(NULL), right(NULL) {}
};

node* insert(node* root, int val) 
{
    if (root == NULL) 
	{
        return new node(val);
    }

    if (val < root->data) 
	{
        root->left = insert(root->left, val);
    } 
	else if (val > root->data) 
	{
        root->right = insert(root->right, val);
    }

    return root;
}

node* findMin(node* root) 
{
    while (root->left != NULL) 
	{
        root = root->left;
    }
    return root;
}

node* del(node* root, int val) 
{
    if (root == NULL)
	{
		return root;
	} 

    if (val < root->data) 
	{
        root->left = del(root->left, val);
    } 
	else if (val > root->data) 
	{
        root->right = del(root->right, val);
    } 
	else 
	{
    	
        if (root->left == NULL && root->right == NULL) 
		{
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) 
		{
            node* temp = root;
            root = root->right;
            delete temp;
        } 
		else if (root->right == NULL) 
		{
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else 
		{
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
}

void preorder(node* root) 
{
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) 
{
    if (root == NULL)
	{
		return;
	} 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root) 
{
    if (root == NULL)
	{
		return;
	} 
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() 
{
    node* root = NULL;

    root= insert(root, 4);
    root= insert(root, 2);
    root= insert(root, 3);
    root= insert(root, 5);
    root= insert(root, 1);
    root= insert(root, 7);
    root= insert(root, 6);

    cout<<"PREORDER\n";
    preorder(root);
    cout<<"\nINORDER\n";
    inorder(root);
    cout<<"\nPOSTORDER\n";
    postorder(root);

    root=del(root, 5);

    cout<<"\nAFTER DELETE 5:\n";
    cout<<"PREORDER\n";
    preorder(root);
    cout<<"\nINORDER\n";
    inorder(root);
    cout<<"\nPOSTORDER\n";
    postorder(root);

    return 0;
}
