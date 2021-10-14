#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
    	sort(arr,arr+n);
    	
    	int minimum;
    	int maximum;
    	
    	int result = arr[n-1]-arr[0];
    	
    	for(int i=1;i<=n-1;i++){
    		if(arr[i]>=k && arr[n-1]>=k){
    			maximum = max(arr[i-1]+k, arr[n-1]-k);
    			minimum = min(arr[0]+k,arr[i]-k);
    			
    			result = min(result, maximum-minimum);
			}
		}
    	
		return result;    	
    }
};

int main(){
	int k=5, n = 10;
	int arr[] = {2,6,3,4,7,2,10,3,2,1};
	
	Solution sol;

	cout<<"\nminimum value: "<<sol.getMinDiff(arr,n,k);
	
	return 0;
}
