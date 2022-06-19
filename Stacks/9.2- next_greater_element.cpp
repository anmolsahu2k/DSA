// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
     vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> res(n);
        stack<long long> st;
        st.push(n-1);
        res[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            //keep popping if current ele is greater than top
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(st.empty())
                res[i]=-1;
            else
                //else st.top() is the next greater ele of current ele
                res[i]=arr[st.top()];
            st.push(i);
        }
        return res;
    }
    // vector<long long> nextLargerElement(vector<long long> arr, int n){
    //     vector<long long> res(n);
    //     stack<long long> st;
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(arr[i]);
    //             res[i]=-1;
    //         }
    //         else
    //         {
    //             if(arr[i]<st.top())
    //             {
    //                 res[i]=st.top();
    //                 st.push(arr[i]);
    //             }
    //             else
    //             {
    //                 while(!st.empty() && arr[i]>=st.top())
    //                     st.pop();
    //                 if(!st.empty())
    //                     res[i]=st.top();
    //                 else
    //                     res[i]=-1;
    //                 st.push(arr[i]);
    //             }
    //         }
    //     }
    //     return res;
    // }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends