// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
        int largest=i;
        int lc=2*i+1;
        int rc=2*i+2;
        if(lc<n&&arr[largest]<arr[lc])
            largest=lc;
        if(rc<n&&arr[largest]<arr[rc])
            largest=rc;
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        
    }
    
    // Main function to do heap sort
    void buildHeap(int arr[], int n) {
        int startIndex=(n/2)-1;
        for(int i=startIndex;i>=0;i--)
            heapify(arr,n,i);
    }
    
    
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>1;i--)
        {
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
        swap(arr[0],arr[1]);
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends