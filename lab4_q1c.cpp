//stack from array
#include <iostream>
using namespace std;

//class for stack 
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
		cout<<"inserted "<<value<<endl;
	}
	//function for pop
	void pop(){
		if(top==-1){}
		else{top=top-1;}
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
				cout<<arr[i]<<"->";
				i--;
			}
		cout<<"NULL"<<endl;}
		return;
	}
	//top element
	void topelement(){
		cout<<"top element is "<<arr[top]<<endl;
	}
	//size
	void size(){
		cout<<"size="<<top+1<<endl;
	}
};

int main(){
	stack s1;
	s1.push(23);
	s1.push(89);
	s1.push(41);
	s1.push(58);
	s1.isempty();cout<<s1.isempty()<<endl;
	s1.topelement();
	s1.display();
	s1.size();
	s1.pop();
	s1.display();
	s1.size();
	return 0;
}
