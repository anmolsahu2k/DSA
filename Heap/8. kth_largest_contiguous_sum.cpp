// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int> presum(N+1);
        priority_queue<int,vector<int>,greater<int>> pq;
        presum[0]=0;
        presum[1]=Arr[0];
        for(int i=2;i<=N;i++)
            presum[i]=presum[i-1]+Arr[i-1];
        for(int i=1;i<=N;i++)
        {
            for(int j=i;j<=N;j++)
            {
                int x=presum[j]-presum[i-1];
                if(pq.size()<K)
                    pq.push(x);
                else
                {
                    if(pq.top()<x)
                    {
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends