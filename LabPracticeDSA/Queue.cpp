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
	   
	    void enque(int x;) 
	    {    
	        if(rear==size-1) 
			{
	            cout<<"Queue Overflow"<<endl;
	        } 
	        else 
			{
	            if(front == -1) 
				{
	                front = 0;
	            }
	            rear++;
	            arr[rear]=x;
	        }
	    }
	    
	    void Deque() 
	    {
	        if(front==-1 || front>rear) 
			{
	            cout <<"Queue Underflow"<<endl;
	            return;
	        } 
	        else 
			{
	            cout<<"Element deleted: "<<arr[front]<<endl;
	            front++;
	        }
	    }
	    
	    void Display() 
	    {
	        if(front==-1) 
			{
	            cout<<"Queue is empty"<<endl;
	        } 
	        else 
			{
	            cout << "Queue elements are: | ";
		        for (int i = rear; i >= front; i--) 
				{
		            cout << arr[i] << " ";
		        }
		        cout<<"|";
		        cout << endl;
	        }
	    }
};

int main()
{
    que q(50); 
    
    q.enque(8);
    q.enque(9);
    q.Display();
    
    q.enque(7);
    q.enque(6);
    q.Display();
    
    q.Deque();
    q.Deque();
    q.Display();
    return 0;
}

