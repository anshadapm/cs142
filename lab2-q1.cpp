#include<iostream>
using namespace std;

class Node{
	public:
	//data
	int data;
	//pointer to the next
	Node * next;
	// Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }	
};

class LinkedList{
	public:		
	//head->node ptr
	Node * head;
	Node * tail;	
	//constructer
	LinkedList(){
		head = NULL;
	    tail = NULL;
	}
	//insert
	void insert(int value){
		//if first node is added
		Node * temp = new Node;
		//insert value in node
		temp->data = value;
		//if there is only one node
		if(head==NULL){
			head=temp;
		}
		//for other node
		else{
			tail->next=temp;
		}
		tail=temp;
	}
	//insert element at perticular position
	void insertAt(int pos,int value){
		//reach the place of position 
		Node * current = head;
		int i=1;
		while(i<pos-1){		
			current = current->next;
			i++;
		}
		//create a node for new
		Node * temp = new Node;
		temp->data = value;
		//moving ptrs
		temp->next = current->next;
		current->next = temp;
	}
	//deletion of last element
	void delet(){
		//temp store tail
		Node * temp = tail;
		Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
	}
	//delete node at a position
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
	//count items
	void countItems(){
		Node * current = head;
		int i=0;
		while(current != NULL){
			i++;
			current=current->next;
		}
		cout<<"No of items in the linkedlist is "<<i<<endl;
	}
	//display
	void display(){
		Node * current = head;
		while(current != NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<endl;
	}
		
};

int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.countItems();
	l1.delet();
	l1.display();
	l1.countItems();
    l1.insertAt(2,7);
	l1.display();
	l1.countItems();
	l1.deleteAt(2);
	l1.display();
	l1.countItems();	
	return 0;
}
