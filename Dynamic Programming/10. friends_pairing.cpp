// https://youtu.be/SHDu0Ufjyk8?t=463
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long long int dp[n+1];
        long long int m=pow(10,9)+7;
        for(int i=0;i<2;i++)
            dp[i]=1;
        // if(n<=0)
        //     return 1;
        for(int i=2;i<n+1;i++)
            dp[i]=(dp[i-1]+(i-1)*dp[i-2])%m;
        // return countFriendsPairings(n-1)+(n-1)*countFriendsPairings(n-2);
        return dp[n]%m;
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends