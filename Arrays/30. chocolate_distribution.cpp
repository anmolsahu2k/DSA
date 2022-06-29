// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long minDiff=a[m-1]-a[0];
    for(int i=1;m-1+i<n;i++)
    {
		//eg., 1,3,4,7,9,9,12,56 diff between 3(1) and 9(5)
		//diff b/w ith and i+(m-1)th element 
        minDiff=min(minDiff,a[m-1+i]-a[i]);
    }
    return minDiff;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends