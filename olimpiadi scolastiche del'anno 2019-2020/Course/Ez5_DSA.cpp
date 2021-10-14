#include<iostream>

using namespace std;

void negativeSorter(int arr[], int n);

int main(){
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	negativeSorter(arr,n);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

void negativeSorter(int arr[], int n){
	int temp;
	int cont = 0;
	
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			temp = arr[cont];
			arr[cont] = arr[i];
			arr[i] = temp;
			cont++; 
		}
	}
}
