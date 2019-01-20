//Doubly linked list 

#include<iostream>
using namespace std;

//class
class node{
	//declarations
	public:
	int data;
	//pointers
	node * next;
 	node * prev;
	//constructer 
 	node(int value){
		//makes ptr NULL
		prev = NULL;
		next = NULL;
		data = value;
	}
};

class doubleLL{
	public:
	//pointers
	node * head;
	//constructer
	doubleLL(){
		head = NULL;
	}
	//function to insert elements
	void insert(int value){
  		//creating node
		node * temp = new node(value);  // node()
		//if there is only one node
		if(head==NULL){
			head = temp;
		}
		//for others
		else{
			node * curr = head;
			while(curr->next!=NULL){
				curr=curr->next;
			}
				curr->next=temp;
				temp->prev=curr;

			
		}
	}
	//to display
	void display(){
		//declare the node
		node * curr = head;
		node * last;
		cout<<"Print elements : ";
		//loop
		while(curr!=NULL){
			cout<<curr->data<<"->";
			//store curr in last
			last = curr;
			//move forward
			curr=curr->next;
		}
		cout<<"NULL"<<endl;
		cout<<"Print elements in reverse order : ";
  		while(last!=NULL){
			cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
		}
		cout <<"NULL"<< endl; 
	}
	//to insert at a position
	void InsertAt(int pos ,int value){
		cout<<"Insert "<<value<<" at position number "<<pos<<" in the DLL"<<endl;
		node * curr = head;
		int i=1;
        //reach place before position
		while(i<pos-1){
			curr=curr->next;
			i++;
		}
		//create node
		node * temp = new node(value);
		//moving ptrs
		temp->next = curr->next;
		curr->next = temp;
		temp->prev = curr;
		temp->next->prev = temp;
		
    }
	//to delete at position
    void DeleteAt(int pos){
		cout<<"Delete the element at position "<<pos<<endl;
        // pointer
		node * curr = head;
		int i=1;
		//reach place before position
		while(i<pos-1){
			curr=curr->next;
			i++;
		}
		//moving ptrs
		curr->next = curr->next->next;
		curr->next->prev=curr;
    }
	// Deletes the last element.
    void Del(){
		cout<<"Delete the last element"<<endl;
        //pointer
		node * curr = head;
		node * temp;
		if(head == NULL){}
		else if (head -> next == NULL){ head = NULL;}
		else{
		//to reach just before position
			while(curr->next->next != NULL){
				curr=curr->next;
			}
			curr->next = temp;
			curr->next=NULL;
			delete temp;	
		}
    }
	// Counts the Number of items.
    void CountItems(){
        //pointer
		node * curr = head;
		int i;
		while(curr!=NULL){
			curr=curr->next;
			i++;
		}
		cout<<"No of elements in the Doubly linked list is "<<i<<endl;
    }

};

int main(){
	doubleLL dl1;
	for(int i= 1; i < 11; i++){
        dl1.insert(i);
    }
	dl1.display();
	dl1.InsertAt(3,11);
	dl1.display();
	dl1.DeleteAt(3);
	dl1.display();
	dl1.Del();
	dl1.display();
	dl1.CountItems();
	return 0;
}
