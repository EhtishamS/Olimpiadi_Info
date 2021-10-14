#include<iostream>

using namespace std;

int max(int x, int y){
	return (x>y)? x : y;
}

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n <= 1)
            return 0;
        
        if(arr[0]==0)
            return -1;
        
        int maxReach = arr[0];
        int step = arr[0];
        int jump = 1;
        
        int i=1;
        for(;i<n;i++){
            if(i == n-1)
                return jump;
            
            maxReach = max(maxReach, i+arr[i]);
            
            step--;
            
            if(step==0){
                jump++;
                
                if(i>=maxReach)
                    return -1;
                
                step = maxReach - i;
            }
        }
        
        return -1;
    }
};

int main(){
	int n = 10;
	int arr[] = {1,3,5,9,7,2,6,7,6,8,9};
	
	Solution obj;
	
	cout<<"The output is: "<<obj.minJumps(arr,n);
	
	return 0;
}
