// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int i,totalGoodCnt=0,currBadCnt=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]<=k)
                totalGoodCnt++;
        }
        //eg., 2, 7, 9, 5, 8, 7, 4, k=6
        //window size is totalGoodCnt(3)
        for(i=0;i<totalGoodCnt;i++)
        {
            if(arr[i]>k)
                currBadCnt++;
        }
        //initially currBadCnt is 2 (elements in current window({2,7,9})> k(6))
        //{7,9,5} - 2
        //{9,5,8} - 2
        //{5,8,7} - 2
        //{8,7,4} - 2
        int ans=currBadCnt;
        for(i=totalGoodCnt;i<n;i++)
        {
            //increasing currBadCnt(if any element in current window > k(6))
            if(arr[i]>k)
                currBadCnt++;
            //decreasing currBadCnt(if any element in previous window > k(6))
            if(arr[i-totalGoodCnt]>k)
                currBadCnt--;
            ans=min(ans, currBadCnt);
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends