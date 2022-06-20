#include<iostream>
#include<stack>
using namespace std;
int prec(char c)
{
    if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else 
        return 0;
}
string infixToPrefix(string s)
{
    stack<char> st;
    string res="";
    for(int i=s.length()-1;i>=0;i--)
    {
        if((s[i]>='a' &&s[i]<='z') ||(s[i]>='A' &&s[i]<='Z')||(s[i]>='0' &&s[i]<='9'))
            res=s[i]+res;
        else if(s[i]==')')
            st.push(s[i]);
        else if(s[i]=='(')
        {
            while(st.top()!=')')
            {
                res=st.top()+res;
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(s[i])<prec(st.top()))
            {
                res=st.top()+res;
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res=st.top()+res;
        st.pop();
    }
    return res;
}
int main()
{
    string s = ("(A-B/C)*(A/K-L)");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}