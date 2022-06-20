// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert_at_bottom(stack<int> &st, int x)
    {
        //Base
        if(st.empty())
            st.push(x);
        else
        {
            int y=st.top();
            st.pop();
            //Hypothesis- applying on smaller i/p
            insert_at_bottom(st,x);
            //Induction
            //After inserting x at bottom, insert the top element which was popped
            st.push(y);
        }
    }
    void reverseStack(stack<int> &st)
    {
        //Base
        if(!st.empty())
        {
            int x=st.top();
            st.pop();
            //Hypothesis-applying on smaller i/p
            reverseStack(st);
            //Induction
            //after stack is reversed insert the top element at the bottom
            insert_at_bottom(st,x);
        }
    }
    vector<int> Reverse(stack<int> St){
        //Reverse stack
        reverseStack(St);
        vector<int> arr;
        while(!St.empty())
        {
            arr.push_back(St.top());
            St.pop();
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends