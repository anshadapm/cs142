//stack from queue
#include <iostream>
using namespace std;

class queue{
	public:
	//declaring the peremeters
	int front,end;
	int arr[20];
	//constructer
	queue(){
		front=0;
		end=-1;
	}
	//add element
	void enqueue(int value){
		arr[++end]=value;
		cout<<"inserted "<<value<<endl;
	}
	//to display
	void display(){
		if(end==-1){cout<<"no elements"<<endl;}
		else{
		//loop from end to reach
		for(int i=end;i>=front;i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;	}
	}
	//to show top element
	void topelement(){
		cout<<"top element is "<<arr[end]<<endl;
	}
	//to delete last element
	void dequeue(){
		for(int i=front;i<end;i++){
			arr[i]=arr[i+1];
		}
		end=end-1;
	}
	//to print size
	void size(){
		cout<<"size = "<<end+1<<endl;
	}
	//check is empty or not
	bool isempty(){
		if(end==-1){return true;}
		else{ return false;}
	}
};
//class  
class stack{
	public:
	int top;
	queue q1;
	//constructer
	stack(){
		top=q1.end;
	}
	//push
	void push(int value){
		q1.enqueue(value);
	}
	//pop
	void pop(){
		q1.end=q1.end-1;
	}
	//to print size
	void size(){
		q1.size();
	}
	//check is empty or not
	bool isempty(){
		q1.isempty();
	}
		//to display
	void display(){
		q1.display();
	}
	//to show top element
	void topelement(){
		q1.topelement();
	}

};

int main(){
	stack s1;
	s1.push(45);
	s1.push(78);
	s1.push(16);
	s1.push(89);
	s1.topelement();
	s1.size();
	s1.display();
	s1.pop();
	s1.display();
}
