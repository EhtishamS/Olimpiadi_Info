///*
//
//Given an array arr[] and a number K where K is smaller than size of array, 
//the task is to find the Kth smallest element in the given array. 
//It is given that all array elements are 
//distinct.
//
//Input:
//	N = 6
//	arr[] = 7 10 4 3 20 15
//	K = 3
//	Output : 7
//	Explanation :
//	3rd smallest element in the given 
//	array is 7.
//*/
//#include<iostream>
//
//using namespace std;
//
//int kthSmallest(int arr[], int size, int k);
//
//#define MAX 100
//
//int main(){
//	int arr[MAX];
//	int size;
//	int k;
//	
//	do{
//		cin>>size;
//		cin>>k;
//	}while(size<=0 || size>MAX || k>size);
//	
//	for(int i=0;i<size;i++){
//		cin>>arr[i];
//	}
//	
//	cout<<kthSmallest(arr,size,k);
//	
//	return 0;
//}
//
//int kthSmallest(int arr[], int size, int k){
//	int min;
//	
//	for(int i=0;i<size-1;i++){
//		min = i;
//		for(int j=i+1;j<size;j++){
//			if(arr[min]>arr[j]){
//				min = j;
//			}
//		}
//		
//		int temp = arr[min];
//		arr[min] = arr[i];
//		arr[i] = temp;
//	}
//	
//	
//	return arr[k-1];
//}


// C++ implementation of worst case linear time algorithm
// to find k'th smallest element
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int partition(int arr[], int l, int r, int k);

// A simple function to find median of arr[].  This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++){
            median[i] = findMedian(arr+l+i*5, 5);
    	}
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5); 
            i++;
        }    

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthSmallest(arr, l, pos-1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// It searches for x in arr[l..r], and partitions the array 
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Driver program to test above methods
int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k);
    
    cout<<endl;
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}
    return 0;
}


