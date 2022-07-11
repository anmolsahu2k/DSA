#include<iostream>
#include<vector>
using namespace std;
int subsetDiff(vector<int> arr,int diff)
{
    int N=arr.size();
    int sum=0,c=0;
    for(int i=0;i<N;i++)
    {
        sum+=arr[i];
    }
    //s1-s2=diff
    //s1+s2=sum
    //=> s1=(diff+sum)/2
    int s=(diff+sum)/2;
    vector<vector<int>> dp(N+1,vector<int>(sum+1,0));
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<s+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[N][s];
}
int main()
{
    vector<int> arr={1,1,2,3};
    int diff=1;
    cout<<subsetDiff(arr,diff);
    return 0;
}