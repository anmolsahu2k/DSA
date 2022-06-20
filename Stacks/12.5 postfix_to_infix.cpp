#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    return false;
}
string getInfix(string s)
{
    stack<string> st;
    for(int i=0;i<s.length();i++)
    {
        if(isOperator(s[i]))
        {
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push('('+op2+s[i]+op1+')');
        }
        else
            st.push(string(1,s[i]));
    }
    return st.top();
}
int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}