/*
Write a C function to return minimum and maximum in an array. 
Your program should make the minimum number of comparisons. 
*/
#include<iostream>

using namespace std;

#define MAX 100

void minMax(int arr[],int size,int &min, int &max);

int main(){
	int arr[MAX];
	int size;
	int min , max;
	
	do{
		cin>>size;
	}while(size<=0 || size>MAX);
	
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	
	minMax(arr,size,min,max);
	
	cout<<min<<" "<<max;

	return 0;
}

void minMax(int arr[],int size,int &min, int &max){
	min = max = arr[0];
	
	for(int i=1;i<size;i++){
		if(max<arr[i]){
			max = arr[i];
		} else if(min>arr[i]){
			min = arr[i];
		}
	}
}

