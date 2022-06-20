// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    bool isOperator(char c)
    {
        if(c=='*'||c=='/'||c=='+'||c=='-')
            return true;
        return false;
    }
    
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i=0;i<S.length();i++)
        {
            if(isOperator(S[i]))
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                if(S[i]=='*')
                    st.push(op2*op1);
                else if(S[i]=='/')
                    st.push(op2/op1);
                else if(S[i]=='-')
                    st.push(op2-op1);
                else
                    st.push(op2+op1);
            }
            else
                st.push(S[i]-'0');
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends