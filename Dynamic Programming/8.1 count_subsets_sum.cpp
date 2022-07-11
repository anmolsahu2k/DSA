#include<iostream>
#include<string>
using namespace std;
int count_subsets(int arr[],int n, int x)
{
    int dp[n+1][x+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<x+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            //1 subset can be made by each element for sum=0 i.e. null subset
            if(j==0)
                dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            //arr[N-1]<=sum(when element is less than target sum)
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][x];
}
int main()
{   int arr[]={1,2,3,3};
    cout<<count_subsets(arr,4,6);
    return 0;
}