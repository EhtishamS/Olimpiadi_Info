/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
Explanation: 
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.
*/

#include<iostream>

using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int count = 0;
        
        for(int i=0;i<n;i++){
        	for(int j=0;j<n&&a[i]!=-1;j++){
        		if(i==j)
        			continue;
        		else {
        			if(a[i]==a[j]){
        				a[j]=-1;
					}
				}
			}
			if(a[i]!=-1)
				count++;
			
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<m&&b[i]!=-1;j++){
				if(i==j)
					continue;
				else{
					if(b[i]==b[j]){
						b[j]=-1;
					}
				}
			}
			if(b[i]!=-1)
				count++;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m&&a[i]!=-1;j++){
				if(a[i]==b[j]){
					count--;
					b[j]=-1;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		
		cout<<"\n";
		
		for(int i=0;i<m;i++){
			cout<<b[i]<<" ";
		}
		
		return count;
    }
};

int main(){
	int a[] = {9,1,9,1,9,1,0};
	int b[] = {9,8,7,6,5,4,3,2,1};
	int n = 7;
	int m = 9;
	
	Solution sol;
	cout<<"\n"<<sol.doUnion(a,n,b,m);
	
	
	return 0;
}
