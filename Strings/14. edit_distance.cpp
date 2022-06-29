#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int editDist(int x, int y, string s1, string s2)
{
    vector<vector<int>>dp(x+1,vector<int>(y+1,0));
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y]+abs(x-y)-1;
    // RECURSION
    //different lengths compared due to else statement
    // if(x==0||y==0)
    //     return 0;
    // if(s1[x-1]==s2[y-1])
    //     return editDist(x-1,y-1,s1,s2);
    // else
    // {
    //     return 1+min(editDist(x-1,y,s1,s2),editDist(x,y-1,s1,s2));
    // }
}

int main()
{
    cout<<editDist(3,11, "dbb","fdfaccddfac");
    return 0;
}
