//queue from linkedlist
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
	void delet(){
		Node*temp=new Node;
		Node*current=head;
		while(current->next->next!=NULL){
			current=current->next;
		}
		
		current->next=NULL;
	}
};
//class
class queue{
	public:
	Linkedlist l1;
	Node*end;
	Node*front;
	queue(){
		front=NULL;
		end=l1.head;
	}
	//add element
	void enqueue(int value){
		l1.insertAt(1,value);
	}
	//display
	void display(){
		l1.display();
	}
	//delet
	void dequeue(){
		end=l1.head;
		l1.delet();
	}
	//isempty
	bool isEmpty(){
        if(l1.head == NULL) return true;
        return false;
    }
	//size
	int size(){
		cout<<"size="<<l1.countItems()<<endl;
	}
	//top element
	void topDisplay(){
		cout<<l1.head->data<<endl;
    }
	
};

int main(){
	queue q1;
	q1.size();
	cout<<q1.isEmpty()<<endl;
	q1.enqueue(76);
	q1.enqueue(58);
	q1.enqueue(39);
	q1.enqueue(12);
	q1.topDisplay();
	q1.display();
	cout<<q1.isEmpty()<<endl;
	q1.dequeue();
	q1.display();
	q1.size();
}
