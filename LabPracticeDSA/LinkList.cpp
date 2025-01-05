#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		
		node():next(NULL){}
		node(int val):data(val), next(NULL){}
		
};

class list
{
	private:
		node* head;
		
	public:
		list():head(NULL){}
		
		void insertstart(int val)
		{
			node* new_node=new node(val);
			
			if(head==NULL)
			{
				head=new_node;
			}
			else
			{
				new_node->next=head;
				head=new_node;
			}
		}
		
		void insertend(int val)
		{
			node* new_node=new node(val);
			
			if(head==NULL)
			{
				head=new_node;
			}
			else
			{
				node *temp=head;
				while(temp->next != NULL)
				{
					temp=temp->next;
			    }
			    temp->next=new_node;
			}
		}
		
		void insertmiddle(int val, int pos)//value and position
		{
		    node* new_node = new node(val);
		    if (pos <= 0 || head == NULL) 
		    {
		        insertstart(val); 
		        return;
		    }
		
		    node* temp = head;
		    for (int i = 0; i < (pos - 1) && temp->next != NULL; i++) 
		    {
		        temp = temp->next;
		    }
		    new_node->next = temp->next;  
		    temp->next = new_node;
		}
		
		void delstart()
		{
		    if (head != NULL) 
		    {
		        node *temp = head; 
		        head = head->next; 
		        delete temp;
		    }
		    else
		    {
		    	cout<<"Empty";
			}
		}
		
		void delend()
		{
			if (head != NULL) 
		    {
		        node *temp = head; 
		        while(temp->next->next != NULL)
		        {
		        	temp=temp->next;
				}
				delete temp->next;
				temp->next=NULL;
		    }
		    else
		    {
		    	cout<<"Empty";
			}
		}
		
		void delmiddle(int val)
		{
		    if (head == NULL) 
		    {
		        cout << "Empty" << endl;
		        return;
		    }
		
		    if (head->data == val) 
		    {
		        node *temp = head;
		        head = head->next;
		        delete temp;
		        return;
		    }
		
		    node *temp = head;
		    while (temp->next != NULL && temp->next->data != val)
		    {
		        temp = temp->next;
		    }
		
		    if (temp->next == NULL) 
		    {
		        cout << "Value not found!" << endl;
		        return;
		    }
		
		    node *Delete = temp->next;
		    temp->next = temp->next->next;
		    delete Delete;
		}

		
		void display()
		{
			node*  temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL";
		}
		
		void sort()
		{
		    if (head == NULL || head->next == NULL)
		    {
		        return;
		    }
		    else
		    {
		        node *temp = head;
		        
		        while (temp != NULL)
		        {
		            node *nxtnode = temp->next;
		            
		            while (nxtnode != NULL)
		            {
		                if (temp->data > nxtnode->data)
		                {
		                    swap(temp->data, nxtnode->data);
		                }
		                nxtnode = nxtnode->next; 
		            }
		            temp = temp->next;
		        }
		    }
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
	l.insertend(10);
	l.insertend(6);
	l.insertend(1);
}

int main()
{
	list l;
	providedlist(l);
	
	l.display();
	cout<<endl;
	
	l.sort();
	
	l.display();	
}
