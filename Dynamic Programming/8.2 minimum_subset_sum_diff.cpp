// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    int minDiff=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        //SEE IMAGE
        //the last row of dp table contains all the subset sums that can be obtained from the given array
        //these subset sum values can be used till s1=sum/2(then s2=sum/2,diff=minimum) to get s1 such that abs(sum-s1-s1) is minimum
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[n][j]==true)
                minDiff=min(minDiff,abs(sum-2*j));
        }
        return minDiff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends