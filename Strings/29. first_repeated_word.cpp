// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string,int> mp;
        int maxCount=0;
        int secondMax=0;
        string res;
        string maxString;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(maxCount<itr->second)
            {
                secondMax=maxCount;
                res=maxString;
                maxCount=itr->second;
                maxString=itr->first;
            }
            if(secondMax<itr->second && maxCount>itr->second)
            {
                secondMax=itr->second;
                res=itr->first;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends