#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int dp[MAX][MAX];
//Recursive->Memoization->Tabulation(Best Approach)
int knapSack(int W, int wt[], int val[], int n, int dp[][MAX]) 
{ 
    if(n==0||W==0)
        return 0;
    if(dp[W][n]!=-1)
        return dp[W][n];
    if(wt[n-1]<=W)
        return dp[W][n]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1,dp), knapSack(W,wt,val,n-1,dp));
    else
        return dp[W][n]=knapSack(W,wt,val,n-1,dp);
}

int main()
 {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    // double pointer to declare the
    // table dynamically

    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < W+1; i++)
        for (int j = 0; j < n + 1; j++)
            cout<<dp[i][j];
    cout<<knapSack(W, wt, val, n, dp)<<endl;   
	return 0;
 }