// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array
// 3 test cases not passing
class Solution{
  public:
    int minJumps(int arr[], int n){
        int i,jumps=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==0)
                return -1;
            else if(arr[i]==1)
                jumps++;
            else
            {
                int steps=arr[i];
                int maxReach=arr[i+1]+i+1;
                if(steps>=n-i)
                    return jumps+1;
                else
                    jumps++;
                while(steps>0)
                {
                    i++;
                    steps--;
                    if(maxReach<arr[i]+i)
                        maxReach=arr[i]+i;
                }
                if(maxReach>=n-1)
                    return jumps+1;
                else
                    i=maxReach;
                cout<<i<<endl;
            }
        }
        return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends