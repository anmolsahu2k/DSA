// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> res(n);
        stack<int> st;
        st.push(n-1);
        res[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty()&&arr[i]<=arr[st.top()])
                st.pop();
            if(st.empty())
                res[i]=-1;
            else
                res[i]=arr[st.top()];
            st.push(i);
        }
        return res;
    } 
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends