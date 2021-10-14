/*
Given an array of integers nums containing n+1 integers where each integer is in the range [1,n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space (0(1)).

Example:
Input nums[]: {1,3,4,2,2};
Output: 2;
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

int main(){
	int n = 4;
	int arr[] = {1,3,4,2,2};
	vector<int> nums;
	
	for(int i=0;i<n+1;i++){
		nums.push_back(arr[i]);
	}
	
	Solution obj;
	cout<<obj.findDuplicate(nums);
	
	return 0;
}
