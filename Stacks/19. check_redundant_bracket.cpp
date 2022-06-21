/* C++ Program to check whether valid
expression is redundant or not*/
#include <bits/stdc++.h>
using namespace std;

// Function to check redundant brackets in a
// balanced expression

bool isOperator(char c)
{
    if(c=='*'||c=='/'||c=='+'||c=='-')
        return true;
    return false;
}
bool checkRedundancy(string& str)
{
	stack<char> st;
    int flag=0;
    for(int i=0;i<str.length();i++)
    {
        flag=0;
        if(str[i]!=')')
            st.push(str[i]);
        else
        {
            while(!st.empty() &&st.top()!='(')
            {
                if(isOperator(st.top()))
                    flag=1;
                st.pop();
            }
            st.pop();
            if(flag==0)
                return true;
        }
    }
    return false;
}

// Function to check redundant brackets
void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// Driver code
int main()
{
	string str = "((a+b))";
	findRedundant(str);

	str = "(a+(b)/c)";
	findRedundant(str);

	str = "(a+b*(c-d))";
	findRedundant(str);

	return 0;
}
