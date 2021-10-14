/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

problem: time exeeded.
*/

#include<iostream>

using namespace std;

int main(){
	int a[] = {0, 2, 1, 2, 0};
	int n = sizeof(a)/sizeof(a[0]);
	int cont = 0;
	int temp;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			if(a[j] == i){
				temp = a[j];
				a[j] = a[cont];
				a[cont] = temp;
			
				cont++;
			}
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}

/*
int zero=0,one=0,two=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero++;
        }
        else if(a[i]==1)
        {
            one++;
        }
        else 
        {
            two++;
        }
    }
    int count=0;
    while(count!=n)
    {
        if(zero>0){
        	a[count] = 0;
        	zero--;
    	} else if(one>0){
    		a[count] = 1;
    	} else {
    		a[count] = 2;
    	}
    	
    	count++;

    }	
*/
