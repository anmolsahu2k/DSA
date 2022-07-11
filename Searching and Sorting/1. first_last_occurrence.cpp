// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> pos;
    int l=0,h=n-1,mid,flag=0;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(arr[mid]>x)
            h=mid-1;
        else if(arr[mid]<x)
            l=mid+1;
        else
        {
            int k=mid;
            while(arr[mid]==x)
                mid--;
            pos.push_back(mid+1);
            while(arr[k]==x)
                k++;
            pos.push_back(k-1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        return {-1,-1};
    return pos;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
