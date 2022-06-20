#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    return false;
}
string preToPost(string s)
{
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(isOperator(s[i]))
        {
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push(op1+op2+s[i]);
        }
        else
            st.push(string(1,s[i]));
    }
    return st.top();
}
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}