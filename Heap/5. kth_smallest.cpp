// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void heapify(int arr[],int n,int i)
    {
        int smallest=i;
        int lc=2*i+1;
        int rc=2*i+2;
        if(lc<n&&arr[smallest]>arr[lc])
            smallest=lc;
        if(rc<n&&arr[smallest]>arr[rc])
            smallest=rc;
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            heapify(arr,n,smallest);
        }
    }
    void buildHeap(int arr[],int n)
    {
        for(int i=n/2-1;i>=0;i--)
            heapify(arr,n,i);
    }
    int kthSmallest(int arr[], int l, int r, int k)
    {
        int ans;
        int n=r-l+1;
        buildHeap(arr,n);
        for(int i=n-1;i>n-1-k;i--)
        {
            ans=arr[0];
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
        return ans;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends