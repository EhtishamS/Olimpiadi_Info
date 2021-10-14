/*
Given an array (or string), the task is to reverse the array/string.

Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}
*/

#include<iostream>

using namespace std;

#define MAX 100

int main(){
	int arr[MAX];
	int size;
	int temp;
	
	//This asks the size of the array
	do{
		cout<<"Enter the size of the array: ";
		cin>>size;
	}while(size<=0 || size>MAX);
	
	//This gonna take the input form the user
	cout<<"\nINSERT:\n";
	for(int i=0;i<size;i++){
		cout<<"Enter a value ["<<i<<"]: ";
		cin>>arr[i];	
	}
	
	//This gonna showcase the input that we got form the user
	cout<<"\nINPUT:\n";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"\t";
	}
	
	//This is the algorithm that solves the problem
	// it goes from 0 to half of the size
	for(int i=0;i<size/2;i++){
		temp = arr[(size-1)-i];
		arr[(size-1)-i] = arr[i];
		arr[i] = temp;
	}
	
	cout<<"\nOUTPUT:\n";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}
