// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long prefix=1,suffix=1, maxProd=INT_MIN;
        //subarray starts from either prefix or suffix depending on position of 0s 
        //eg., -1 , -3, -10, 0, 60 -> subarray starts from suffix
        //eg., 2, 3, 4, 5, -1, 0 -> subarray starts from prefix 
	    for(int i =0;i<n;i++)
	    {
	        prefix*=arr[i];
	        suffix*=arr[n-i-1];
	        maxProd=max(maxProd, max(prefix,suffix));
            if(prefix==0)
                prefix=1;
            if(suffix==0)
                suffix=1;
	    }
	    return maxProd;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends