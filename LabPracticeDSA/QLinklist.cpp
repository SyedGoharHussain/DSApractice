#include<iostream>
using namespace std;

class Node 
{
	public:
	    int data;
	    Node* next;
	
	    Node(int val) : data(val), next(NULL) {}
};

class Queue 
{
	private:
	    Node* front;
	    Node* rear;
	
	public:
	    Queue() : front(NULL), rear(NULL) {}
	
	    void enQ(int val) 
		{
	        Node* newNode = new Node(val);
	        if (rear == NULL) 
			{
	            front = rear = newNode;
	            return;
	        }
	        rear->next = newNode;
	        rear = newNode;
	    }
	
	    void deQ() 
		{
	        if (front == NULL) 
			{
	            cout << "Queue underflow" << endl;
	            return;
	        }
	        cout << front->data << endl;
	        Node* temp = front;
	        front = front->next;
	        delete temp;
	        
	        if (front == NULL) 
	        {
	            rear = NULL;
			}

	    }
	
	    int Front() 
		{
	        if (isEmpty()) 
			{
	            cout << "Queue is empty" << endl;
	            return -1;
	        }
	        return front->data;
	    }
	
	    bool isEmpty() 
		{
	        return front == NULL;
	    }
};

int main() 
{
    Queue q;
    q.enQ(10);
    cout << "Front: " << q.Front() << endl;
    q.enQ(20);
    cout << "Front: " << q.Front() << endl;
    q.enQ(30);
    cout << "Front: " << q.Front() << endl;

    cout << "\nDequeuing:\n";
    q.deQ();
    q.deQ();
    q.deQ();
    q.deQ();
}

