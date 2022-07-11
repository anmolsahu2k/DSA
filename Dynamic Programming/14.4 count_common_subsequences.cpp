#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int SCS(int m, int n, string X, string Y)
{
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));    
    //using LCS
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
                //last char same(abcdt,efght)->{(abdct,efgh)+(abcd,efght)+t}
                dp[i][j]=dp[i][j-1]+dp[i-1][j]+1;
            else
                //last char not same(abcdt, efgh)->{(abcd,efgh)+(abcdt,efg)-(abcd,efg)}
                //(abcd,efg) is present in both (abcd,efgh) and (abcdt, efg)
                //Here we subtract dp[i-1][j-1] once because it is present in both dp[i][j – 1]
                // and dp[i – 1][j] and gets added twice.
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    //total common subsequences between given substrings
    cout<<"    b a d e a"<<endl;
    for(int i=0;i<m+1;i++)
    {
        if(i>0 && i<m+1)
            cout<<X[i-1]<<" ";
        else
            cout<<"  ";
        for(int j=0;j<n+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}

int main()
{
    cout<<SCS(5,5, "aedab","badea");
    return 0;
}
