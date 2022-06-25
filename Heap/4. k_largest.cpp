// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void heapify(int arr[],int n, int i)
    {
        int largest=i;
        int lc=2*i+1;
        int rc=2*i+2;
        if(lc<n && arr[largest]<arr[lc])
            largest=lc;
        if(rc<n && arr[largest]<arr[rc])
            largest=rc;
        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    void buildHeap(int arr[], int n)
    {
        int startIndex=(n/2)-1;
        for(int i=startIndex;i>=0;i--)
            heapify(arr,n,i);
    }
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> res;
	    buildHeap(arr,n);
	    for(int i=n-1;i>n-1-k;i--)
	    {
	        res.push_back(arr[0]);
	        swap(arr[0],arr[i]);
	        heapify(arr,i,0);
	    }
	    return res;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends