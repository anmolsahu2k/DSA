#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> printlcs(int x, int y, vector<int> s1, vector<int> s2)
{
    vector<vector<vector<int>>> dp(x+1,vector<vector<int>>(y+1));
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
                dp[i][j].push_back(s1[i-1]);
            }
            else
            {
                if(dp[i-1][j].size()>dp[i][j-1].size())
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[x][y];
}

int main()
{
    vector<int> v= printlcs(6,5, {3,4,1,2,1,3},{1,2,3,4,1});
    for(auto i : v)
    {   
        cout<<i<<" ";
    }
    return 0;
}
