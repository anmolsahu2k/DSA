// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    //Similar to unbounded knapsack
    //See space optimized
    int cutRod(int price[], int n) {
        int length[n];
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(length[i-1]<=j)
                    dp[i][j]=max(dp[i][j-length[i-1]]+price[i-1],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends

//OR Recursively
// if(n<=0)
//     return 0;
// int max_val=INT_MIN;
// for(int i=0;i<n;i++)
// {
        //     max_val=max(max_val,cutRod(price,n-i-1)+price[i]);
// }
// return max_val;

// OR O(n) space
// int val[n+1];
// val[0] = 0;
// int i, j;

// Build the table val[] in bottom up manner and return the last entry
// from the table
// one by one, partition the given rod of length `n` into two parts
// of length (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0) and take maximum
// for (i = 1; i<=n; i++)
// {
// 	int max_val = INT_MIN;
// 	for (j = 0; j < i; j++)
// 		max_val = max(max_val, price[j] + val[i-j-1]);
// 	val[i] = max_val;
// }

//val[2]=max obtainable price for rod of size 2;
// return val[n];
