#include <iostream>
using namespace std;

class node
{
	public:
	    int data;
	    node* next;
	
	    node() : next(NULL) {}
	    node(int val) : next(NULL), data(val) {}
};

class list 
{
	private:
	node* head;
	
	public:
	list() : head(NULL) {}
	
	void insertstart(int val) 
	{
	    node* new_node = new node(val);
	    if (head == NULL) 
		{
	        head = new_node;
	        new_node->next = head;
	    } 
		else 
		{
	        node* temp = head;
	        while (temp->next != head) 
			{
	            temp = temp->next;
	        }
	        new_node->next = head;
	        temp->next = new_node;
	        head = new_node;
	    }
	}
	
	void insertend(int val) 
	{
	    node* new_node = new node(val);
	    if (head == NULL) 
		{
	        head = new_node;
	        new_node->next = head;
	    } else {
	        node* temp = head;
	        while (temp->next != head) 
			{
	            temp = temp->next;
	        }
	        new_node->next = head;
	        temp->next = new_node;
	    }
	}
	
	void insertmiddle(int val, int pos) 
	{
	    node* new_node = new node(val);
	    if (pos <= 0 || head == NULL) 
		{
	        insertstart(val);
	        return;
	    }
	    node* temp = head;
	    for (int i = 0; i < (pos - 1) && temp->next != head; i++) 
		{
	        temp = temp->next;
	    }
	    new_node->next = temp->next;
	    temp->next = new_node;
	}
	
	void delstart() 
	{
	    if (head == NULL) return; 
	
	    if (head->next == head) 
		{ 
	        delete head;
	        head = NULL;
	        return;
	    }
	
	    node* temp = head;
	    while (temp->next != head) 
		{
	        temp = temp->next;
	    }
	    node* toDelete = head;
	    head = head->next;
	    temp->next = head;
	    delete toDelete;
	}
	
	void delend() 
	{
	    if (head == NULL) return;
	
	    if (head->next == head) 
		{
	        delete head;
	        head = NULL;
	        return;
	    }
	
	    node* temp = head;
	    while (temp->next->next != head) 
		{
	        temp = temp->next;
	    }
	    delete temp->next;
	    temp->next = head; 
	}
	
	void delmiddle(int val) 
	{
	    if (head == NULL) 
		{
			return;
		} 
	
	    node* temp = head;
	    node* prev = NULL;
	
	    do 
		{
	        if (temp->data == val) 
			{
	            if (prev == NULL) 
				{
	                delstart();
	            } 
				else 
				{
	                prev->next = temp->next;
	                delete temp; 
	            }
	            return;
	        }
	        prev = temp;
	        temp = temp->next;
	    } while (temp != head);
	}
	
	void display() 
	{
	    if (head == NULL) 
		{
			return;
		} 
	
	    node* temp = head;
	    do 
		{
	        cout << temp->data << ",";
	        temp = temp->next;
	    } 
		while (temp != head);
	    cout << endl;
	}
};

void providedlist(list &l) 
{
    l.insertend(5);
    l.insertend(7);
    l.insertend(4);
    l.insertend(3);
    l.insertend(8);
    l.insertend(9);
    l.insertend(2);
    l.insertend(6);
    l.insertend(1);
}

int main() 
{
    list l;

    cout << "==============Provided list============\n";
    providedlist(l);
    l.display();

    cout << "\n\n==============Insertion at start============\n";
    l.insertstart(7);
    l.display();

    cout << "\n\n==============Insertion at Middle============\n";
    l.insertmiddle(0, 4); // 0 is value, 4 is position
    l.display();

    cout << "\n\n==============Insertion at end============\n";
    l.insertend(2);
    l.display();

    cout << "\n\n==============Deletion at start============\n";
    l.delstart();
    l.display();

    cout << "\n\n==============Deletion of 9 at Middle============\n";
    l.delmiddle(9);
    l.display();

    cout << "\n\n==============Deletion at end============\n";
    l.delend();
    l.display();

    return 0;
}

