// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        long long int dp[n+1][r+1];
        long long int h=pow(10,9)+7;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<r+1;j++)
            {
                if(j==0||j==i)
                    dp[i][j]=1;
                if(i<j)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<r+1;j++)
            {
                dp[i][j]=dp[i-1][j-1]%h+dp[i-1][j]%h;
            }
        }
        
        return dp[n][r]%h;
    }
};

//RECURSIVE
// Base Cases-> C(n, 0) = C(n, n) = 1, n > r
// if (r > n)
//     return 0;
// if (r == 0 || r == n)
//     return 1;

// Recur-> C(n, k) = C(n-1, k-1) + C(n-1, k)
// return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends