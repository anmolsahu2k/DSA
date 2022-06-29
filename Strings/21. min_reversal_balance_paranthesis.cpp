#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}





int countRev (string s)
{
    int oc=0;
    int rev=0;
    if(s.length()%2!=0)
        return -1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='}')
        {
            if(oc==0)
            {
                rev++;
                oc++;
            }
            else
                oc--;
        }
        else
        {
            oc++;
        }
    }
    rev+=oc/2;
    return rev;
}