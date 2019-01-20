//circular linked list

#include<iostream>
using namespace std;

//classes
class node{
	//declare
	public:
	int data;
	//pointers
	node * next;
	//constructer
	node(int value){
		next = NULL;
		data = value;
	}
};
class circularLL{
	//declare
	public:
	//ptr
	node * head;
	
	//constructer
	circularLL(){
		head=NULL;
	}
	//insert
	void insert(int value){
		//declare
		node * temp = new node(value);
		if(head==NULL){
			head=temp;
		}
		else{
			node * curr = head;
			while(curr->next!=head){
				curr=curr->next;
				
			}
			curr->next=temp;
		}
		temp->next = head;
	}
	//display
	void display(){
		node * curr = head;
		if(head==NULL){
			cout<<"no elements"<<endl;
		}
		else if(head->next==head){
			cout<<head->data<<endl;
		}
		else{
		
			while(curr->next!=head){
				cout<<curr->data<<"->";
				curr=curr->next;
			}
			cout << curr -> data ;
        	cout << endl;
		}
	}
	//to insert at a position
	void InsertAt(int value, int pos){
        //declare
        node * curr = head;
        //to reach before pos
        int i=1;
        while(i<pos-1){
        	curr=curr->next;
        	i++;
		}
		node * temp = new node(value);
		temp->next = curr->next;
		curr->next = temp;
		
    }
    //delete at a pos
    void DeleteAt(int pos){
        //declare
        node * curr = head;
        //to reach before pos
        int i=1;
        while(i<pos-1){
        	curr=curr->next;
        	i++;
		}
		node * temp;
		temp = curr->next;
		curr->next=curr->next->next;
		delete temp;
    }
    void Delet(){
        //declare
        node * curr = head;
		node * temp;
		//if there is no elem
		if(head==NULL){}
        //if there is only one element
        else if(head->next==head){ 
			head = NULL;
			delete head;
		}
		//if there is 2 element
		else if(head->next->next==head){
			temp=head->next;
			head=temp->next;
			head->next=head;
			delete temp;
		}
		//for others
		else{
			//to reach before head
       		while(curr->next->next!=head){
        		curr=curr->next;
			}
			
			temp = curr->next;
			curr->next=curr->next->next;
			delete temp;
		}
    }
    void CountItems(){
        node * curr = head;
        if(head==NULL){
			cout<<"no elements in CLL "<<endl;
		}
		else if(head->next==head){
			cout<<"no of element in CLL is 1"<<endl;
		}
		else{
			int i=1;
			while(curr->next!=head){
				i++;
				curr=curr->next;
			}
			cout<<"no of element in CLL is "<<i<<endl;
		}
		
    }
};

int main(){		
	circularLL cl1;
	cl1.insert(1);
	cl1.insert(2);
	cl1.insert(3);
	cl1.insert(4);
	cl1.display();
	cl1.InsertAt(9,3);
	cl1.display();
	cl1.DeleteAt(3);
	cl1.display();
	cl1.Delet();
	cl1.display();
	cl1.CountItems();
	return 0;
}
