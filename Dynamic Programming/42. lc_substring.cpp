#include<iostream>
#include<string>
#include<vector>
using namespace std;
//for recursive, add count to function definition and reset to 0 if X[i-1]!=Y[j-1]
int main()
{

    string X="OldSite:GeeksforGeeks.org";
    string Y= "NewSite:GeeksQuiz.com";
    int n = X.length();
    int m = Y.length();
    //stores count of common characters in current matching substring
    vector<vector<int>> dp( n+1 , vector<int> (m+1, 0));
    int maxCount=dp[0][0];
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            //comparing all combinations of lengths of X and Y using 'for loop' 
            if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            //reset count of common characters after discontinuity
                dp[i][j]=0;
            maxCount=max(maxCount,dp[i][j]);
        }
    }
    cout<<maxCount<<endl;
    return 0;

}