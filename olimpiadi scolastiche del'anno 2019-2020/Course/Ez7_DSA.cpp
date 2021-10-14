/*
Given an array, rotate the array by one position in clock-wise direction.
 

Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
*/
#include<iostream>

using namespace std;

void rotate(int a[], int N);

int main(){
	int N = 5;
	int a[] = {1, 2, 3, 4, 5};
	
	rotate(a,N);
	
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	
	return 0;	
}

void rotate(int a[], int N){
	int temp;
	
	temp = a[N-1];
	for(int i=N-1;i>0;i--){
		a[i] = a[i-1];
	}
	a[0] = temp;
}

