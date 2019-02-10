//queue from stack
#include<iostream>
using namespace std;

class stack{
	public:
	int top;
	int arr[20];
	//constructer
	stack(){
		top=-1;
	}
	//function for push 
	int push(int value){
		top++;
		arr[top]=value;
	}
	//function for pop
	void pop(){
		if(top==-1){}
		else{top=top-1;}
	}
	//top element
	int topelement(){
		return arr[top];
		
	}
	//is empty
	bool isempty(){
		if(top==-1){ return true;}
		else{return false;}	
	}
	//display
	void display(){
		if(top==-1){cout<<"no elements"<<endl;}
		else{
	    	int i=top;
			while(i!=-1){
				cout<<arr[i]<<"  ";
				i--;
			}cout<<endl;
		}
		return;
	}
	//size
	void size(){
		if(top==-1){cout<<"size=0"<<endl;}
		else{
			int i;
			while(i<=top){ 
				i++;
			}
		cout<<"size="<<i<<endl;}
	}
};
class queue{
	public:
	int end,front;
	stack s1;
	stack s2;
	queue(){
		front=s1.top+1;
		end=s1.top;
	}
   //add element
	void enqueue(int value){	
		s1.push(value);
	}
	//dequeue
	void dequeue(){
		//create a new stack s2 to store elements of stack s1
		while(s1.top!=-1){
			//s2 stores the value of s1
			s2.push(s1.topelement());
			//the elements delete from s1 
			s1.pop();
		}
		//delete top most element of s2 which we need to remove from queue
		s2.pop();
		//s1 restores the elements from s2
		while(s2.top!=-1){
			s1.push(s2.topelement());
			//delete elements from s2 and s2 becomes empty
			s2.pop();
		}
	}
	//display
	void display(){
		s1.display();
	}
	//is empty
	bool isempty(){
		s1.isempty();
	}
	//size
	void size(){
		s1.size();
	}
	//top element
	void topelement(){
		cout<<"top element is "<<s1.topelement()<<endl;
	}
};

int main(){
	queue q1;
	q1.enqueue(89);
	q1.enqueue(78);
	q1.enqueue(25);
	q1.enqueue(43);
	q1.topelement();
	q1.display();
	q1.isempty();cout<<q1.isempty()<<endl;
	q1.size();
	
	q1.dequeue();
	q1.display();
}
