#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int SCS(int m, int n, string X, string Y)
{
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                //when there will be 0 elements in any one string(when length=0),
                //the remaining no. elements in the other string will be stored(returned)
                //because that will be the answer for that subproblem("","abcd"=>4)
                if(i==0)
                    dp[i][j]=j;
                if(j==0)
                    dp[i][j]=i;
            }
        }
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    
    
    //using LCS
    // for(int i=1;i<m+1;i++)
    // {
    //     for(int j=1;j<n+1;j++)
    //     {
    //         if(X[i-1]==Y[j-1])
    //             dp[i][j]=dp[i-1][j-1]+1;
    //         else
    //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //     }
    // }
    // //Length of the shortest supersequence = (Sum of lengths of given two strings) - (Length of LCS of two given strings) 
    // return m+n-dp[m][n];
}

int main()
{
    cout<<SCS(3,11, "dbb","fdfaccddfac");
    return 0;
}
