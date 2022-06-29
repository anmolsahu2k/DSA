// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int k=-1,i,maxRow=-1;
	    for(i=0;i<m;i++)
	    {
	        if(arr[0][i]==1)
	        {
	            k=i;
	            maxRow=0;
	            break;
	        }
	    }
	    if(k==0)
	        return maxRow;
	    else if(k==-1)
	        k=m-1;
	    else
	        k--;
	    for(i=1;i<n && k>=0;i++)
	    {
	        while(arr[i][k]==1)
	        {
	            k--;
	            maxRow=i;
	        }
	    }
	    return maxRow;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends