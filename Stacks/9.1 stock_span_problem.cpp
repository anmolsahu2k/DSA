// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int> st;
        vector<int> res;
        //index of 1st ele
        st.push(0);
        //span of 1st ele
        res.push_back(1);
        for(int i=1;i<n;i++)
        {
            //popping till larger ele found || st.empty
            while(!st.empty() && price[st.top()]<=price[i])
                st.pop();
            //if stack not empty, span=no. of ele popped 
            if(!st.empty())
                res.push_back(i-st.top());
            //else push i+1
            else
                res.push_back(i+1);
            //push current ele index in stack
            st.push(i);
        }
        return res;
        
    }
    // vector <int> calculateSpan(int price[], int n)
    // {
    //     stack<int> st;
    //     stack<int> st2;
    //     vector<int> res(n);
    //     for(int i=0;i<n;i++)
    //     {
    //       if(st.empty())
    //       {
    //           st.push(price[i]);
    //           res[i]=1;
    //           st2.push(res[i]);
    //       }
    //       else
    //       {
    //           if(price[i]<st.top())
    //           {
    //               res[i]=1;
    //               st.push(price[i]);
    //               st2.push(res[i]);
    //           }
    //           else
    //           {
    //               res[i]=1;
    //               while(!st.empty() && price[i]>=st.top())
    //               {
    //                   res[i]+=st2.top();
    //                   st.pop();
    //                   st2.pop();
    //               }
    //               st.push(price[i]);
    //               st2.push(res[i]);
    //           }
    //       }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends