// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //Using LCS
        int m=A.length();
        string B = string(A.rbegin(),A.rend());
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(A[i-1]==B[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][m];
        //Also see raw implementation(without LCS)
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends