// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int res=0;
        int n=str.length();
        int priority;
        map<char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        for(int i=0;i<n-1;i++)
        {
            if(mp[str[i]]>=mp[str[i+1]])
                res+=mp[str[i]];
            else
                res-=mp[str[i]];
        }
        return res+mp[str[n-1]];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends