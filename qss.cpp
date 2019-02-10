#include<iostream>
using namespace std;

//function paratition
int partition(int arr[],int low,int high){
	int i=low,pvt=high;
	while(i<pvt){//cout<<arr[i]<<arr[pvt-1];
		if(arr[i]>arr[pvt]){
			int temp=arr[i];
			arr[i]=arr[pvt-1];
			arr[pvt-1]=arr[pvt];
			arr[pvt]=temp;
			pvt=pvt-1;
		}
		else{i++;
		}
	}
	return pvt;
}
//qs
void quicksort(int arr[],int low,int high){
	if(low<high){
		
		int p=partition(arr,low,high);
		quicksort(arr,low,p-1);
		quicksort(arr,p+1,high);
	}
	else return;
}
int main(){
	int i,n,k,arr[50];
	cout<<"enter the no of elements for the array";
	cin>>n;
	for(i=0;i<n;i++){
		 cout<<"enter element for "<<i+1<<"th position";
		 cin>>arr[i];
	}
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++){
		 cout<<arr[i]<<" ";
	}
	return 0;
}
