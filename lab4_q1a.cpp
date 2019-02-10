//stack from linkedlist
//library
#include<iostream>

using namespace std;

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};
class Linkedlist{
	public:
	//ptrs
	Node*head;
	Node*tail;

	Linkedlist(){
		//initial value
		head=NULL;
		tail=NULL;
	}
	//to insert
	void insert(int value){
		Node * temp = new Node; 
		temp->data = value;	
		//to add first element
	 	if(head==NULL){
			head = temp;	
			tail = temp;
		}	
	    else{		
			tail->next = temp;
			tail = temp;
		}
	}	
	//count items
	int countItems(){	  	
		Node * current = head;
		int i=0;			
		while(current!=NULL){
			i++;	
			current=current->next;
		}
		return (i);
	}		
	
	//inserting new node at a position
    void insertAt(int pos,int value){
		Node * current = head;	
		 //if positionn is 1	 
		if(pos==1){			
			Node * temp=new Node;		
			head = temp;		
			temp->data = value;		
			temp->next = current;
		}		 
		else{			
			int i=2;	
			while(i<pos){			
			     current=current->next;
		         i=i+1;
			}
			Node*temp=new Node;		
			temp->data=value;	
			temp->next=current->next;	
			current->next=temp;
		}	
	}
	//function for display
    void display(){		
		Node *current=head;	
		while(current!=NULL){	
			//running till NULL
			cout<<current->data<<"->";
			current=current->next;
			}
		cout<<"NULL"<<endl;
	}

	void deleteAt(int pos){
		//reach the place before position
		Node * current = head;
		int i=0;
		while(i<pos-2){
			current=current->next;
			i++;
		}
		
        //reach the position
        Node * temp = current;
        i=1;
        while(i<pos){
			current=current->next;
			i++;
        }
        //moving pointers
		temp -> next = current->next; 
		current->next = temp;
		//delete at position
		delete current;
	}
	void deletFt(){
		Node*temp=new Node;
		temp=head;
		head=head->next;
		delete temp;
	}
};

class stack{
    public:
	Node * top;
	Linkedlist l1;
	stack(){
	    top= NULL;
	}
    //push on top
	void push(int value){
		l1.insertAt(1,value);
		top = l1.head;
	}
	//pops the top
	void pop(){
		l1.deletFt();
		top=l1.head;
	}	
	bool isEmpty(){
        if(top == NULL) return true;
        return false;
    }
    int size(){
        return l1.countItems();
    }
    void topDisplay(){
		cout<<top->data<<endl;
    }
    void display(){
        l1.display();
    }
};


int main(){
    stack s1;

    for(int i = 0; i < 5 ; i++)
       { s1.push(i);}
	s1.topDisplay();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
	cout<<"size of stack is "<<s1.size()<<endl;
	cout<<s1.isEmpty()<<endl;
	
}
