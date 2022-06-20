#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    return false;
}
string postToPre(string s)
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
            st.push(s[i]+op2+op1);
        }
        else
            st.push(string(1,s[i]));
    }
    return st.top();
}
int main()
{
    string post_exp = "ABC/-AK/L-*";
 
    // Function call
    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}