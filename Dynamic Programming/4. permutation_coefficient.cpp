#include<iostream>
using namespace std;
int nPr(int n,int r)
{
    int dp[n+1][r+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<r+1;j++)
        {   
            //P(n,0)=1, n>r
            if(i<j)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<r+1;j++)
        {
            //P(n, r) = P(n-1, r) + r* P(n-1, r-1)   
            dp[i][j]=dp[i-1][j] + j*dp[i-1][j-1];
        }
    }
    return dp[n][r];
}
int main()
{
    cout<<nPr(10,1);
    // OR O(n)
    // int n=10;
    // int k=2,pfact=1;
    // for(int i=n;i>=n-k+1;i--)
    // {
    //     pfact*=i;
    // }
    // cout<<pfact;
    return 0;
}