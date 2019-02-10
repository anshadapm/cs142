//queue from array
#include <iostream>
using namespace std;

//class  
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

int main(){
	queue q1;
	q1.enqueue(56);
	q1.enqueue(75);
	q1.enqueue(42);
	q1.enqueue(98);
	q1.topelement();
	q1.display();
	q1.size();
	q1.dequeue();
	q1.display();
	q1.isempty();cout<<q1.isempty()<<endl;
}
