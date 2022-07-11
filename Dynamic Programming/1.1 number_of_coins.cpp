// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	//Similar to Unbounded Knapsack
	int minCoins(int coins[], int M, int V) 
	{ 
		//store coins count for sum=i and n=first j elements of coins
	    int dp[M+1][V+1];
	    for(int i=0;i<M+1;i++)
	    {
	        for(int j=0;j<V+1;j++)
	        {
				//when no coin present, number of coins required is infinity(INT_MAX) for all sums
	            if(i==0)
	                dp[i][j]=INT_MAX-1;//(-1 for using +1 later in line 28)
				//when sum=0, then coins required are 0
	            if(j==0)
	                dp[i][j]=0;
	        }
	    }
	    for(int i=1;i<M+1;i++)
	    {
	        for(int j=1;j<V+1;j++)
	        {
	            if(coins[i-1]<=j)
					//min(Increase count by 1 if coin picked, else don't pick)
	                dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
		//means subset not possible 
	    if(dp[M][V]==INT_MAX-1)
	        return -1;
	    return dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends