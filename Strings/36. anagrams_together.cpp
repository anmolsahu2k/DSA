// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<string> list;
        list= string_list;
        int n=string_list.size();
        map<string,vector<int>> mp;
        for(int i =0;i<n;i++)
            sort(list[i].begin(),list[i].end());
        for(int i=0;i<n;i++)
            mp[list[i]].push_back(i);
        int k=0;
        vector<int> temp;
        vector<vector<string>> arr(mp.size());
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {   
            temp=itr->second;
            for(int i=0;i<temp.size();i++)
            {
                arr[k].push_back(string_list[temp[i]]);
            }
            k++;
        }
        return arr;
    }   
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends