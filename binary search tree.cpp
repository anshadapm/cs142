#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node * left;
	node * right;
	node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};

class bist{
	public:
	node * root;
	bist(){
		root=NULL;
	}
	void insert(int value){
		inserthelper(root,value);
	}
	void inserthelper(node * curr,int value){
		//base case if cur is null, insert there
		if(curr==NULL){
			curr=new node(value);cout<<curr->data<<" inserted"<<endl;
			if(root==NULL){
				root=curr;
			}
			
		//	return;
		}
	/*	if(root==NULL){
				root=new node(value);cout<<curr->data<<" inserted"<<endl;
			}*/
		//else compare the curr data with value
		else if(value < curr->data){cout<<" at left of "<<curr->data;
			//if value<curr data-> move to left and call insertH
			if(curr->left==NULL) {
			curr->left=new node(value);cout<<" "<<curr->left->data<<" inserted"<<endl;}
			 inserthelper(curr->left,value);
		}
		else if(value > curr->data){
			cout<<" at right of "<<curr->data;
			//else move right and call insertH
			if(curr->right==NULL) {
			curr->right=new node(value);cout<<" "<<curr->right->data<<" inserted"<<endl;}
			else inserthelper(curr->right,value);
		}	

	}
	void display(){
		display2(root);
	}
	void display2(node * curr){
		//base condition
		if(curr==NULL) return;
		//display left
		display2(curr->left);
		cout<<curr->data<<"  ";
		//dis right
		display2(curr->right);
	}
	node * search1(int value){
		return search(value,root);
	}
	node * search(int value,node * curr){
	//	node * curr=root;
		if(curr==NULL || curr->data==value)return curr;
		else if(curr->data>value){
			return search(value,curr->left);
		}
		else {
			return search(value,curr->right);
		}
	}	
};

int main(){
	bist b1;
	b1.insert(4);
	b1.insert(8);
	b1.insert(3);
	b1.insert(2);	
	cout<<"display ";
	b1.display();
	cout<<endl;
	if(b1.search1(1)!=NULL){
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
}
