// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i=0;i<k;i++)
            pq.push({arr[i],i});
        res.push_back(pq.top().first);
        for(int i=k;i<n;i++)
        {
            pq.push({arr[i],i});
            while(pq.top().second<i+1-k)
                pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
  //TIME LIMIT EXCEEDED(56/72 testcases passed)
  //try using map!!
  //USE priority_queue for ease
//   void heapify(vector<int> arr,int heap[], int n, int i) {
//     // Find largest among root, left child and right child
//         int largest=i;
//         int lc=2*i+1;
//         int rc=2*i+2;
//         if(lc<n&&arr[heap[largest]]<arr[heap[lc]])
//             largest=lc;
//         if(rc<n&&arr[heap[largest]]<arr[heap[rc]])
//             largest=rc;
//         if(largest!=i)
//         {
//             swap(heap[largest],heap[i]);
//             heapify(arr,heap,n,largest);
//         }
        
//     }
    
//     // Main function to do heap sort
//     void buildHeap(vector<int> arr,int heap[], int k) {
//         int startIndex=(k/2)-1;
//         for(int i=startIndex;i>=0;i--)
//             heapify(arr,heap,k,i);
//     }
    
    
//     //Function to sort an array using Heap Sort.
        
//     vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
//         vector<int> res;
//         int heap[k];
//         for(int i=0;i<k;i++)
//         {
//             heap[i]=i;
//         }
//         buildHeap(arr,heap,k);
//         for(int i=k;i<n;i++)
//         {
//             res.push_back(arr[heap[0]]);
//             for(int j=0;j<k;j++)
//             {
//                 if(heap[j]<i+1-k)
//                 {
//                     heap[j]=i;
//                     break;
//                 }
//             }
//             buildHeap(arr,heap,k);
//         }
//         res.push_back(arr[heap[0]]);
//         return res;
//     }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends