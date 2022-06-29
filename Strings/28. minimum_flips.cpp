// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int f1=0,f0=0;
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0 && S[i]=='0')
            f1++;
        else if(i%2!=0 && S[i]=='1')
            f1++;
    }
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0 && S[i]=='1')
            f0++;
        else if(i%2!=0 && S[i]=='0')
            f0++;
    }
    return min(f0,f1);
}