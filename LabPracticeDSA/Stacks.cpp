#include <iostream>  
using namespace std;  

#define n 100  

class stack 
{  
	private:  
	    int *arr;  
	    int top;  
	
	public:  
	    stack(): top(-1) 
		{  
	        arr = new int[n];  
	    }  
	
	    void push(int x) 
		{  
	        if (isfull()) 
			{  
	            cout << "\nStack overflow";  
	        } 
			else 
			{  
	            top++;
	            arr[top] = x;
	        }  
	    }  
	
	    void pop() 
		{  
	        if (isempty()) 
			{  
	            cout << "\nStack Underflow";  
	        } else 
			{  
	            top--;  
	        }  
	    }  
	
	    int Top() 
		{  
	        if (top == -1) 
			{  
	            cout << "\nNo element in stack ";  
	            return -1;
	        } 
			else 
			{  
	            return arr[top];  
	        }  
	    }  
	
	    bool isempty() 
		{  
	        return top == -1; 
	    }  
	
	    bool isfull() 
		{  
	        return top == n - 1; 
	    }  
	
	    ~stack() 
		{ 
	        delete[] arr;  
	    }  
};  

int main() {  
    stack st;  
    st.push(7);  
    cout << st.Top() << endl; 
    st.push(4);  
    cout << st.Top() << endl; 
    st.push(6);  
    cout << st.Top() << endl; 
    st.push(8);  
    cout << st.Top() << endl; 
    st.push(9);  
    cout << st.Top() << endl;
    st.push(2);  
    cout << st.Top() << endl;

    st.pop();
	cout << st.Top() << endl;  
    st.pop();  
    cout << st.Top() << endl;
    st.pop();  
    cout << st.Top() << endl;
    st.pop();  
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl; 

    return 0;  
}
