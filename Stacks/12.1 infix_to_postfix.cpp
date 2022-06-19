// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    int prec(char c)
    {
        if(c=='^')
            return 3;
        else if(c=='*'||c=='/')
            return 2;
        else if(c=='+'||c=='-')
            return 1;
        else
            return 0;
    }
  
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string op="";
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='a' && s[i]<='z') ||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
                op=op+s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    op=op+st.top();
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while(!st.empty()&&prec(s[i])<=prec(st.top()))
                {
                    op=op+st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            op=op+st.top();
            st.pop();
        }
        return op;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends