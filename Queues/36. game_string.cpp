// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        sort(s.begin(),s.end());
        priority_queue<int> q;
        int c=1,ans=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                c++;
            else
            {
                q.push(c);
                c=1;
            }
        }
        q.push(c);
        while(k--)
        {
            int x=q.top();
            q.pop();
            x--;
            q.push(x);
        }
        while(!q.empty())
        {
            int x=q.top();
            q.pop();
            ans=ans+x*x;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends