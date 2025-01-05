#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		node():next(NULL){}
		node(int val):data(val), next(NULL){}
};

class stack
{
	node* top;
	
	public:
		stack():top(NULL){}
		
		void push(int val)
		{
			node *newnode=new node(val);
			newnode->next=top;
			top=newnode;
		}
		
		void pop()
		{
			if(top==NULL)
			{
				cout<<"stack underflow";
			}
			else
			{
				cout<<top->data<<endl;
				node* temp=top;
				top=top->next;
				delete temp;
			}
		}
		int Top()
        {
            if (isempty()) 
            {
                cout << "\nNo element in stack\n";
                return -1; 
            }
            return top->data; 
        }
        
        bool isempty()
        {
        	return top==NULL;
		}
};

int main()
{
	stack st;
	st.push(3);
	cout<<st.Top()<<endl;
	st.push(2);
	cout<<st.Top()<<endl;
	st.push(4);
	cout<<st.Top()<<endl;
	st.push(5);
	cout<<st.Top()<<endl;
	cout<<"\npopping\n";
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
}

