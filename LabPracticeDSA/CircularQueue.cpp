#include<iostream>
using namespace std;

class que
{
    int *arr;
    int rear;
    int front;
    int size;

public:
    que(int n): arr(new int[n]), rear(-1), front(-1), size(n) {}

    void enque(int x) 
    {
        if ((rear + 1) % size == front) 
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        
        if (front == -1)
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % size;
        }
        
        arr[rear] = x;
    }

    void Deque() 
    {
        if (front == -1) 
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Element deleted: " << arr[front] << endl;
        
        if (front==rear)
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % size;
        }
    }

    void Display() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements are: | ";
        int i = front;
        while (true) 
        {
            cout<<arr[i]<<" ";
            if (i == rear)
			{
				break;	
			}   
            i=(i+1)%size;
        }
        cout << "|" << endl;
    }
   
};

int main()
{
    que q(5); 

    q.enque(9);
    q.enque(5);
    q.Display();

    q.enque(7);
    q.enque(3);
    q.enque(2); 
    q.Display();

    q.Deque();
    q.Deque();
    q.Display();
    
    q.enque(1);
    q.Display();
    
    return 0;
}

