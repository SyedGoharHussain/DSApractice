#include <iostream>
using namespace std;

class node
{
	public:
	    int data;
	    node* next;
	    node* prev;
	
	    node() : next(NULL), prev(NULL) {}
	    node(int val) : data(val), next(NULL), prev(NULL) {}
};

class list
{
	private:
	    node* head;
	    node* tail;
	
	public:
	    list() : head(NULL), tail(NULL) {}
	
	
	    void insertstart(int val)
	    {
	        node* new_node = new node(val);
	        if (head == NULL) 
	        {
	            head = new_node; 
	            tail = new_node;  
	        }
	        else
	        {
	            new_node->next = head;  
	            head->prev = new_node;
	            head = new_node; 
	        }
	    }
	
	    void insertend(int val)
	    {
	        node* new_node = new node(val);
	        if (head == NULL) 
	        {
	            head = new_node; 
	            tail = new_node;  
	        }
	        else
	        {
	            tail->next = new_node;  
	            new_node->prev = tail;  
	            tail = new_node;        
	        }
	    }
		
		void insertmiddle(int val, int pos)
		{
		    node* new_node = new node(val);
		
		    if (head == NULL || pos <= 0)
		    {
		        insertstart(val);
		    }
		    else
		    {
		        node* temp = head;
		
		        for (int i = 0; i < (pos - 1) && temp->next != NULL; i++)
		        {
		            temp = temp->next;
		        }
		
		        new_node->next = temp->next;  
		        new_node->prev = temp;       
		        temp->next = new_node;       
		
		        if (new_node->next != NULL)  
		        {
		            new_node->next->prev = new_node; 
		        }
		        else
		        {
		            tail = new_node;  
		        }
		    }
		}
		
		void delstart()
		{
		    if (head != NULL)
		    {
		        node* temp = head;          
		        head = head->next;          
		
		        if (head != NULL)           
		        {
		            head->prev = NULL;    
		        }
		        else
		        {
		            tail = NULL;           
		        }
		
		        delete temp;                
		    }
		    else
		    {
		        cout << "List is empty!" << endl;
		    }
		}
	
			
		void delend()
		{
		    if (head != NULL)
		    {
		        node* temp = tail; 
		        
		        
		        if (head == tail)
		        {
		            head = NULL;
		            tail = NULL;
		        }
		        else
		        {
		            tail = tail->prev;   
		            tail->next = NULL;   
		        }
		
		        delete temp;
		    }
		    else
		    {
		        cout << "List is empty!" << endl;
		    }
		}
	
		void delmiddle(int val)
		{
		    if (head != NULL)
		    {
		        node *temp = head;
		
		        
		        while (temp != NULL && temp->data != val)
		        {
		            temp = temp->next;
		        }
		
		        if (temp == NULL) 
		        {
		            cout << "Value not found!" << endl;
		            return;
		        }
		
		        if (temp == head)
		        {
		            delstart(); 
		            return;
		        }
		
		        if (temp == tail)
		        {
		            delend();  
		            return;
		        }
		
		        temp->prev->next = temp->next; 
		        temp->next->prev = temp->prev;  
		
		        delete temp; 
		    }
		    else
		    {
		        cout << "List is empty!" << endl;
		    }
		}
	
	
	    void display()
	    {
	        node* temp = head;
	        cout << "NULL" <<" <-> ";
	        while (temp != NULL)
	        {
	            cout << temp->data << " <-> ";
	            temp = temp->next;
	        }
	        cout << "NULL" << endl;
	    }
	
		void display_reverse()
		{
			cout << "NULL" <<" <-> ";
			node* temp = tail;
	        while (temp != NULL)
	        {
	            cout << temp->data << " <-> ";
	            temp = temp->prev;
	        }
	        cout << "NULL" << endl;
	   		
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
	
	cout<<"==============Provided list============\n";
	providedlist(l);
	l.display();
	
	cout<<"\n\n==============Insertion at start============\n";
	l.insertstart(7);
	l.display();
	cout<<"\n\n==============Insertion at Middle============\n";
	l.insertmiddle(0,4); //0 is value 4 is position
	l.display();
	cout<<"\n\n==============Insertion at end============\n";
	l.insertend(2);
	l.display();
	
	cout<<"\n\n==============Deletion at start============\n";
	l.delstart();
	l.display();
	cout<<"\n\n==============Deletion of 9 at Middle============\n";
	l.delmiddle(9);
	l.display();
	cout<<"\n\n==============Deletion at end============\n";
	l.delend();
	l.display();
	
	cout<<"\n\n======================REVERSE DISPLAY======================\n\n";
	l.display_reverse();
	
	
}

