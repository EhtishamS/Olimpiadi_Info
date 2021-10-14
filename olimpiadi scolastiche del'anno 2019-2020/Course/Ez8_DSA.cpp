/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

difficulty: medium;
*/
#include<iostream>
#include<climits>

using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n){
    	
        int max_so_far = a[0];
   		int curr_max = a[0];

	   	for (int i = 1; i < n; i++)
	   	{
	        curr_max = max(a[i], curr_max+a[i]);
	        max_so_far = max(max_so_far, curr_max);
	   	}
	   	return max_so_far;
        
    }
};

int main(){
	int N=14;
	int arr[]={74,-72,94,-53,-59,-3,-66,36,-13,22,73,15,-52,75}; 
	
	Solution sl;
	
	
	cout<<sl.maxSubarraySum(arr,N);
	
	return 0;
}
