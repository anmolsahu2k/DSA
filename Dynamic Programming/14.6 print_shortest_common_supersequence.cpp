#include <iostream>
#include <vector>
#include <string>
using namespace std;
string SCS(string X, string Y, int n, int m)
{
    vector<vector<string>>dp(n+1,vector<string>(m+1,""));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0)
                dp[i][j]=Y.substr(0,j);
            if(j==0)
                dp[i][j]=X.substr(0,i);
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1]+X[i-1];
            else
            {
                string a=dp[i-1][j];
                string b=dp[i][j-1];
                if(a.length()<b.length())
                    dp[i][j]=a+X[i-1];
                else 
                    dp[i][j]=b+Y[j-1];
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string X="AGGTAB";
    string Y="GXTXAYB";
    int n=X.length();
    int m=Y.length();
    cout<<SCS(X,Y,n,m);
    return 0;
}