#include<iostream>
#include<vector>
#include<string>
using namespace std;
string printlcs(int x, int y, string s1, string s2)
{
    vector<vector<string>> dp(x+1,vector<string>(y+1,""));
    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            //concatenate the common character
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+s1[i-1];
            else
            {
                if(dp[i-1][j].length()>dp[i][j-1].length())
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[x][y];
    // RECURSION
    //different lengths compared due to else statement
    // if(s1[x-1]==s2[y-1])
    //     return printlcs(x-1,y-1,s1,s2)+s1[x-1];
    // else
    // {
    //     string str1=printlcs(x-1,y,s1,s2);
    //     string str2=printlcs(x,y-1,s1,s2);
    //     if(str1.length()>str2.length())
    //         return str1;
    //     else
    //         return str2;
    // }
}

int main()
{
    cout<<printlcs(6,7, "AGGTAB","GXTXAYB");
    return 0;
}
