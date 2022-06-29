// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
    sort(A,A+n);
    int i,j,k,sum;
    for(i=0;i<n;i++)
    {
        j=i+1;
        k=n-1;
        sum=X-A[i];
        while(j<k)
        {
            if(A[j]+A[k]==sum)
                return true;
            else if(A[j]+A[k]<sum)
                j++;
            else
                k--;
        }
    }
    return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends